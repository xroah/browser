#ifndef _WINDOW_H
#define _WINDOW_H
#endif // _WINDOW_H

#include <gtk/gtk.h>
#include <webkit2/webkit2.h>

void load_page(GtkWidget *, WebKitWebView *, WebKitURIRequest *);
void handle_load_change(WebKitWebView *, WebKitLoadEvent, gpointer);
GtkWidget* create_window(GtkApplication *);
gboolean handle_context_menu(WebKitWebView *, WebKitContextMenu *, GdkEvent *, WebKitHitTestResult *, gpointer);
GtkWidget* handle_web_view_create(WebKitWebView *, WebKitNavigationAction *, gpointer);
