#include <gtk/gtk.h>
#include "title_bar.h"
#define MIN_WIDTH 1024
#define MIN_HEIGHT 700

void create_window(GtkApplication *app, gpointer user_data)
{
    GtkWindow *win = (GtkWindow *) gtk_application_window_new(app);
    TitleBar *title_bar = title_bar_new((GtkWidget *)win);
    GdkGeometry geo =
    {
        .min_width = MIN_WIDTH,
        .min_height = MIN_HEIGHT
    };

    gtk_window_set_titlebar(win, title_bar->bar);
    gtk_window_set_icon_from_file(win, "./icons/logo.png", NULL);
    gtk_widget_show_all((GtkWidget *)win);
    gtk_window_set_default_size(win, MIN_WIDTH, MIN_HEIGHT);
    gtk_window_set_geometry_hints(win, NULL, &geo, GDK_HINT_MIN_SIZE);
}

int main (int argc, char *argv[])
{
    GtkApplication *app = gtk_application_new("x.music", G_APPLICATION_FLAGS_NONE);
    int status;

    g_signal_connect(app, "activate", G_CALLBACK(create_window), NULL);
    status = g_application_run(G_APPLICATION((app)), argc, argv);
    g_object_unref(app);

    return status;
}
