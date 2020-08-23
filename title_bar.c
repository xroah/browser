#include "title_bar.h"
#include<stdlib.h>

void window_destroy(GtkWidget *window, gpointer user_data)
{
    free(user_data);
}

TitleBar* title_bar_new(GtkWidget *window) {
    TitleBar *title_bar = malloc(sizeof(title_bar));
    GtkCssProvider *css_provider = gtk_css_provider_new();
    GtkBuilder *builder = gtk_builder_new_from_file("ui/title-bar.glade");
    title_bar->bar = (GtkWidget *)gtk_builder_get_object(builder, "title-bar");
    title_bar->search_input = (GtkWidget *)gtk_builder_get_object(builder, "search-input");

    gtk_css_provider_load_from_path(css_provider, "css/title-bar.css", NULL);
    gtk_style_context_add_provider_for_screen(
        (GdkScreen *) gtk_widget_get_screen(title_bar->bar),
        (GtkStyleProvider *)css_provider,
        GTK_STYLE_PROVIDER_PRIORITY_APPLICATION
    );
    g_signal_connect(window, "destroy", G_CALLBACK(window_destroy), title_bar);

    return title_bar;
}
