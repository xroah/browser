#include "window.h"

inline static gboolean handle_create(WebKitWebView *wv, GdkEvent  *event, gpointer user_data)
{
    return TRUE;
}

void init_style(GtkWidget *win)
{
    GtkStyleContext *style_ctx = gtk_widget_get_style_context(win);
    GtkCssProvider *css_provider = gtk_css_provider_new();
    gtk_style_context_add_class(style_ctx, "top-window");
    gtk_css_provider_load_from_path(css_provider, "./styles/page.css", NULL);
    gtk_style_context_add_provider_for_screen(
        gtk_window_get_screen((GtkWindow *)win),
        (GtkStyleProvider *) css_provider,
        GTK_STYLE_PROVIDER_PRIORITY_APPLICATION
    );
}

GtkWindow* create_window(GtkApplication *app, WebKitWebView *web_view)
{
    WebKitWebView *wv;
    GtkWindow *win = (GtkWindow *) gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkBox *box = (GtkBox *)gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    Window window =
    {
        .window = win,
        .topbar = create_topbar()
    };



    if (web_view == NULL)
    {
        wv = (WebKitWebView *)webkit_web_view_new();
    }
    else
    {
        wv = web_view;
    }

    window.headerbar = create_headerbar(wv);
    gtk_window_set_titlebar(win, (GtkWidget *)window.headerbar->bar);
    gtk_container_add((GtkContainer *) win, (GtkWidget *)box);
    gtk_widget_set_vexpand((GtkWidget *) wv, TRUE);
    //g_signal_connect(wv, "button-press-event", G_CALLBACK(handle_create), NULL);
    gtk_container_add((GtkContainer *) box, (GtkWidget *)window.topbar->root);
    gtk_container_add((GtkContainer *) box, (GtkWidget *)wv);
    webkit_web_view_load_uri(wv, "https://cn.bing.com");
    gtk_application_add_window(app, win);
    gtk_window_set_default_size(win, 1024, 800);
    gtk_window_set_icon_from_file(win, "./assets/logo.png", NULL);
    g_signal_connect(win, "destroy", G_CALLBACK(gtk_widget_destroyed), NULL);

    init_style((GtkWidget *)win);

    gtk_widget_show_all((GtkWidget *)win);

    return win;
}
