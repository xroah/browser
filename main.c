#include <stdlib.h>
#include <gtk/gtk.h>
#include <webkit2/webkit2.h>

void activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *win = gtk_application_window_new(app);
    GtkCssProvider *css = gtk_css_provider_new();
    GtkStyleContext *style_ctx = gtk_widget_get_style_context(win);
    GtkBuilder *builder = gtk_builder_new_from_file("ui/title-bar.glade");
    GtkWidget *title_bar;

    gtk_css_provider_load_from_path(css, "css/main.css", NULL);
    gtk_style_context_add_provider(style_ctx, (GtkStyleProvider *)css, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    title_bar = (GtkWidget *)gtk_builder_get_object(builder, "title_bar");
    g_print("%d", title_bar == NULL);
    gtk_window_set_titlebar((GtkWindow *)win, title_bar);
    gtk_window_set_default_size((GtkWindow *)win, 1024, 600);
    gtk_widget_show_all(win);
}

int main (int argc, char *argv[])
{
    GtkApplication *app = gtk_application_new("x.music", G_APPLICATION_FLAGS_NONE);
    int status;

    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION((app)), argc, argv);
    g_object_unref(app);

    return status;
}
