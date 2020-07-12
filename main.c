#include <gtk/gtk.h>
#include <webkit2/webkit2.h>

void activate(GtkApplication *, gpointer);
void load_page(GtkWidget *);
void handle_load_change(WebKitWebView *, WebKitLoadEvent, gpointer);

void handle_load_change(WebKitWebView *wv, WebKitLoadEvent evt, gpointer user_data)
{
    GtkWindow *win = (GtkWindow *)user_data;

    switch(evt) {
        case WEBKIT_LOAD_STARTED:
            gtk_window_set_title(win, "loading");
            break;
        case WEBKIT_LOAD_FINISHED:
            gtk_window_set_title(win, webkit_web_view_get_title(wv));
            break;
    }
}

void load_page(GtkWidget *win)
{
    GtkWidget *web_view = webkit_web_view_new();
    WebKitSettings *settings = webkit_settings_new();
    webkit_settings_set_enable_smooth_scrolling(settings, TRUE);
    webkit_settings_set_enable_developer_extras(settings, TRUE);
    webkit_settings_set_user_agent_with_application_details(settings, "Chrome", "83");
    webkit_settings_set_javascript_can_access_clipboard(settings, TRUE);
    webkit_settings_set_javascript_can_open_windows_automatically(settings, TRUE);
    webkit_settings_set_allow_file_access_from_file_urls(settings, TRUE);
    webkit_settings_set_media_playback_allows_inline(settings, TRUE);
    webkit_web_view_set_settings(web_view, settings);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add((GtkContainer *)win, box);
    gtk_container_add((GtkContainer *)box, web_view);
    gtk_box_set_child_packing((GtkBox *)box, web_view, TRUE, TRUE, 0, GTK_PACK_START);

    webkit_web_view_load_uri((WebKitWebView *)web_view, "https://echarts.apache.org/examples/en/editor.html?c=area-stack");
    g_signal_connect(web_view, "load-changed", G_CALLBACK(handle_load_change), win);
}

void activate(GtkApplication *app, gpointer user_data)
{
	GtkWidget *window;

	window = gtk_application_window_new(app);
	gtk_application_add_window(app, (GtkWindow *)window);
	gtk_window_set_default_size(GTK_WINDOW(window), 1024, 720);

	load_page(window);
	gtk_widget_show_all(window);
}

int main(int argc, char *argv[])
{
	GtkApplication *app;
	int status;

	app = gtk_application_new("x.browser", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK (activate), NULL);
	status = g_application_run(G_APPLICATION (app), argc, argv);
	g_object_unref(app);

	return status;
}
