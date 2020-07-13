#include "window.h"

void handle_load_change(WebKitWebView *wv, WebKitLoadEvent evt, gpointer user_data)
{
    GtkWindow *win = (GtkWindow *)user_data;

    switch(evt)
    {
    case WEBKIT_LOAD_STARTED:
        gtk_window_set_title(win, "loading");
        break;
    case WEBKIT_LOAD_FINISHED:
        gtk_window_set_title(win, webkit_web_view_get_title(wv));
        break;
    }
}

gboolean handle_context_menu(
    WebKitWebView *web_view,
    WebKitContextMenu *ctx_menu,
    GdkEvent * evt,
    WebKitHitTestResult * res,
    gpointer user_data
)
{
    g_print("context menu\n");

    return FALSE;
}

GtkWidget* handle_web_view_create(
    WebKitWebView *web_view,
    WebKitNavigationAction *nav_action,
    gpointer user_data
)
{
    WebKitWebView *wv = webkit_web_view_new();
    GtkWindow *orig_win = (GtkWindow *) user_data;
    GtkApplication *app = gtk_window_get_application(orig_win);
    WebKitURIRequest *request = webkit_navigation_action_get_request(nav_action);
    GtkWidget *window = create_window(app);
    load_page(window, wv, request);

    g_print("create signal\n");

    return wv;
}

void load_page(GtkWidget *win, WebKitWebView *wv, WebKitURIRequest *req)
{
    GtkWidget *web_view;

    if (wv == NULL)
    {
        web_view  = webkit_web_view_new();
    }
    else
    {
        web_view = wv;
    }

    WebKitSettings *settings = webkit_settings_new();
    webkit_settings_set_enable_smooth_scrolling(settings, TRUE);
    webkit_settings_set_enable_developer_extras(settings, TRUE);
    webkit_settings_set_user_agent_with_application_details(settings, "Chrome", "83");
    webkit_settings_set_javascript_can_access_clipboard(settings, TRUE);
    webkit_settings_set_javascript_can_open_windows_automatically(settings, TRUE);
    webkit_settings_set_allow_file_access_from_file_urls(settings, TRUE);
    webkit_settings_set_media_playback_allows_inline(settings, TRUE);
    webkit_web_view_set_settings((WebKitWebView *)web_view, settings);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add((GtkContainer *)win, box);
    gtk_container_add((GtkContainer *)box, web_view);
    gtk_box_set_child_packing((GtkBox *)box, web_view, TRUE, TRUE, 0, GTK_PACK_START);
    gtk_widget_show_all(win);

    webkit_web_view_load_request((WebKitWebView *)web_view, req);
    g_signal_connect(web_view, "load-changed", G_CALLBACK(handle_load_change), win);
    g_signal_connect(web_view, "context-menu", G_CALLBACK(handle_context_menu), NULL);
    g_signal_connect(web_view, "create", G_CALLBACK(handle_web_view_create), win);
}

GtkWidget* create_window(GtkApplication *app)
{
    GtkWidget *window;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_application_add_window(app, (GtkWindow *)window);
    gtk_window_set_default_size(GTK_WINDOW(window), 1024, 720);
    gtk_window_set_icon_from_file((GtkWindow *)window, "./assets/logo.png", NULL);

    return window;
}
