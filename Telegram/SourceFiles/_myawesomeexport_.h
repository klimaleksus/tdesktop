
// main.cpp
void _myawesomeexport_MainInit(void);

// mainwidget.cpp
void _myawesomeexport_ChatSelected(void* data);

// history/history_widget.cpp
void _myawesomeexport_ExportRequested(void);

#ifdef _myawesomeexport_cpp
#undef _myawesomeexport_cpp

// Window::PeerMenuExportChat
#include "window/window_peer_menu.h"

// PeerData
#include "data/data_peer.h"

// HINSTANCE, LoadLibraryA, GetProcAddress
#include <windows.h>

PeerData* _myawesomeexport_chatselected_ = NULL;
HINSTANCE _myawesomeexport_dllhandle_ = NULL;

typedef int (__stdcall *_myawesomeexport_myinit)(int);
_myawesomeexport_myinit _myawesomeexport_myinit_ = NULL;

void _myawesomeexport_MainInit(void){
  _myawesomeexport_dllhandle_ = LoadLibraryA("myawesomeexport.dll");
  if(!_myawesomeexport_dllhandle_)
    return;
  _myawesomeexport_myinit_ = GetProcAddress(_myawesomeexport_dllhandle_,"myinit");
  if(_myawesomeexport_myinit_)
    _myawesomeexport_myinit_(0);
};

void _myawesomeexport_ChatSelected(void* data){
  _myawesomeexport_chatselected_ = (PeerData*)data;
  if(!_myawesomeexport_chatselected_)
    return;
  if(!_myawesomeexport_myinit_)
    return;
  _myawesomeexport_myinit_(_myawesomeexport_chatselected_->id);
};

void _myawesomeexport_ExportRequested(void){
  if(!_myawesomeexport_chatselected_)
    return;
  Window::PeerMenuExportChat(_myawesomeexport_chatselected_);
};

#endif

//EOF
