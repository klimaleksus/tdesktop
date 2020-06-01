
void _myawesomeexport_ChatSelected(void* data);
void _myawesomeexport_ExportRequested(void);

#ifndef _myawesomeexport_h_
#define _myawesomeexport_h_

#include "window/window_peer_menu.h"

void* _myawesomeexport_chatselected_ = NULL;

void _myawesomeexport_ChatSelected(void* data){
  _myawesomeexport_chatselected_ = data;
};

void _myawesomeexport_ExportRequested(void){
  if(!_myawesomeexport_chatselected_)
    return;
  Window::PeerMenuExportChat(_myawesomeexport_chatselected_);
};

#endif
