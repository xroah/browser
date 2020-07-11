#include <gtk/gtk.h>
#include <webkit2/webkit2.h>

void activate(GtkApplication *, gpointer);
void load_page(GtkWidget *);
void handle_load_change(WebKitWebView *, WebKitLoadEvent, gpointer);

void handle_load_change(WebKitWebView *wv, WebKitLoadEvent evt, gpointer user_data)
{

    switch(evt) {
        case WEBKIT_LOAD_FINISHED:
            gtk_window_set_title((GtkWindow *)user_data, webkit_web_view_get_title(wv));
            break;
    }
}

void load_page(GtkWidget *win)
{
    GtkWidget *web_view = webkit_web_view_new();
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add((GtkContainer *)win, box);
    gtk_container_add((GtkContainer *)box, web_view);
    gtk_box_set_child_packing((GtkBox *)box, web_view, TRUE, TRUE, 0, GTK_PACK_START);
    gtk_window_set_title(win, "loading");
    webkit_web_view_load_uri((WebKitWebView *)web_view, "https://cn.bing.com");
    g_signal_connect(web_view, "load-changed", G_CALLBACK(handle_load_change), win);
}

void activate(GtkApplication *app, gpointer user_data)
{
	GtkWidget *window;

	window = gtk_application_window_new(app);
	gtk_application_add_window(app, (GtkWindow *)window);
	gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
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
