#ifndef _WINDOW_H
#define _WINDOW_H
#endif // _WINDOW_H

#include <gtk/gtk.h>
#include <webkit2/webkit2.h>

void handle_load_change(WebKitWebView *, WebKitLoadEvent, gpointer);
GtkBuilder* create_window(GtkApplication *, WebKitWebView *);
void load_page(GtkBuilder *, WebKitWebView *, WebKitURIRequest *);
gboolean handle_context_menu(WebKitWebView *, WebKitContextMenu *, GdkEvent *, WebKitHitTestResult *, gpointer);
GtkWidget* handle_web_view_create(WebKitWebView *, WebKitNavigationAction *, gpointer);
void init_web_view_settings(WebKitWebView *);
WebKitWebView* add_web_view(GtkBuilder *, WebKitWebView *);
