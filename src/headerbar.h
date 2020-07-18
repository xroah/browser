#ifndef _HEADERBAR_H
#define _HEADERBAR_H

#include <gtk/gtk.h>
#include <webkit2/webkit2.h>

typedef struct headerbar
{
    GtkButton *add_btn;
    GtkBox *tab_wrapper;
    WebKitWebView *web_view;
    GtkHeaderBar *bar;
} Headerbar;


Headerbar* create_headerbar(WebKitWebView *);

#endif // _HEADERBAR_H
