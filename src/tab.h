#ifndef TAB_H_
#define TAB_H_

#include <gtk/gtk.h>
#include "widgets/tabheader.h"

typedef struct tab {
    WebKitWebView *web_view;
    TabHeader *header;
} Tab;

Tab* create_tab(void);

#endif // TAB_H_
