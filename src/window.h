#ifndef WINDOW_H_
#define WINDOW_H_

#include <gtk/gtk.h>
#include <webkit2/webkit2.h>
#include "topbar.h"
#include "headerbar.h"
#include "webview.h"
#include "tab.h"

void handle_load_change(WebKitWebView *, WebKitLoadEvent, gpointer);
GtkWindow* create_window(GtkApplication *, WebKitWebView *);
void load_page(GtkBuilder *, WebKitWebView *, WebKitURIRequest *);
gboolean handle_context_menu(WebKitWebView *, WebKitContextMenu *, GdkEvent *, WebKitHitTestResult *, gpointer);
GtkWidget* handle_web_view_create(WebKitWebView *, WebKitNavigationAction *, gpointer);
void init_web_view_settings(WebKitWebView *);
WebKitWebView* add_web_view(GtkBuilder *, WebKitWebView *);
void init_style(GtkWidget *win);

typedef struct window {
    Headerbar *headerbar;
    Topbar *topbar;
    WebKitWebView *activate_web_view;
    GtkWindow *window;
} Window;

#endif // WINDOW_H_
