#ifndef HEADERBAR_H_
#define HEADERBAR_H_

#include <gtk/gtk.h>
#include <webkit2/webkit2.h>

typedef struct headerbar
{
    GtkButton *add_btn;
    GtkBox *tab_wrapper;
    WebKitWebView *web_view;
    GtkHeaderBar *bar;
    GtkWidget *titlebar;
} Headerbar;


Headerbar* create_headerbar(WebKitWebView *);
#endif // HEADERBAR_H_
