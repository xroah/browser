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
    WebKitWebView *wv = (WebKitWebView *)webkit_web_view_new_with_related_view(web_view);
    GtkBox *box = (GtkBox *) user_data;
    GtkWindow *window = (GtkWindow *)gtk_widget_get_parent((GtkWidget *) box);
    GtkApplication *app = gtk_window_get_application(window);
    WebKitURIRequest *request = webkit_navigation_action_get_request(nav_action);

    create_window(app, wv);
    load_page(window, wv, request);

    g_print("create signal\n");

    return (GtkWidget *)wv;
}

void init_web_view_settings(WebKitWebView *web_view)
{
    WebKitSettings *settings = webkit_settings_new();
    webkit_settings_set_enable_smooth_scrolling(settings, TRUE);
    webkit_settings_set_enable_developer_extras(settings, TRUE);
    webkit_settings_set_user_agent_with_application_details(settings, "Chrome", "83");
    webkit_settings_set_javascript_can_access_clipboard(settings, TRUE);
    webkit_settings_set_javascript_can_open_windows_automatically(settings, TRUE);
    webkit_settings_set_allow_file_access_from_file_urls(settings, TRUE);
    webkit_settings_set_media_playback_allows_inline(settings, TRUE);
    webkit_web_view_set_settings(web_view, settings);
}

void load_page(GtkWindow *window, WebKitWebView *web_view, WebKitURIRequest *request)
{

    g_signal_connect(
        web_view,
        "load-changed",
        G_CALLBACK(handle_load_change),
        window
    );
    webkit_web_view_load_request(web_view, request);
}

WebKitWebView* add_web_view(GtkBox *box, WebKitWebView *wv)
{
    WebKitWebView *web_view;

    if (wv == NULL)
    {
        web_view  = (WebKitWebView *)webkit_web_view_new();
    }
    else
    {
        web_view = wv;
    }

    init_web_view_settings(web_view);

    gtk_widget_set_vexpand((GtkWidget *)web_view, true);
    gtk_container_add((GtkContainer *)box, (GtkWidget *)web_view);
    g_signal_connect(web_view, "context-menu", G_CALLBACK(handle_context_menu), NULL);
    g_signal_connect(web_view, "create", G_CALLBACK(handle_web_view_create), box);

    return web_view;
}

void create_window(GtkApplication *app, WebKitWebView *web_view)
{
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkBuilder *builder = gtk_builder_new_from_file("./ui/page.ui");
    GtkBox *root_box = (GtkBox *)gtk_builder_get_object(builder, "root-box");
    GtkStyleContext *style_ctx = gtk_widget_get_style_context(window);
    GtkCssProvider *css_provider = gtk_css_provider_new();

    gtk_style_context_add_class(style_ctx, "top-window");
    gtk_css_provider_load_from_path(css_provider, "./styles/page.css", NULL);
    gtk_style_context_add_provider_for_screen(
        gdk_screen_get_default(),
        (GtkStyleProvider *) css_provider,
        GTK_STYLE_PROVIDER_PRIORITY_APPLICATION
    );

    gtk_container_add((GtkContainer *)window, (GtkWidget *)root_box);
    gtk_application_add_window(app, (GtkWindow *)window);
    gtk_window_set_default_size(GTK_WINDOW(window), 1024, 720);
    gtk_window_set_icon_from_file((GtkWindow *)window, "./assets/logo.png", NULL);

    WebKitWebView *wv = add_web_view(root_box, web_view);
    load_page((GtkWindow*) window, wv, webkit_uri_request_new("https://bing.com"));

    GtkButton *refresh_btn = (GtkButton *)gtk_builder_get_object(builder, "refresh-btn");
    gtk_button_set_image(refresh_btn, gtk_image_new_from_file("./assets/refresh.png"));

    gtk_widget_show_all(window);
}
