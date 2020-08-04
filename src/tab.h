#ifndef TAB_H_
#define TAB_H_

#include <webkit2/webkit2.h>
#include "widgets/tabheader.h"

typedef struct tab {
    WebKitWebView *web_view;
    TabHeader *header;
} Tab;

Tab* create_tab(void);
void init_web_view_settings(WebKitWebView *);
void load_page(WebKitWebView *, WebKitURIRequest *);
void handle_load_change(WebKitWebView *, WebKitLoadEvent, gpointer);

#endif // TAB_H_
