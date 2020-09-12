#include "title_bar.h"
#include "settings.h"
#include<stdlib.h>

void window_destroy(GtkWidget *window, gpointer user_data)
{
    free(user_data);
}

gboolean handle_search(GtkWidget *btn, gpointer user_data)
{
    return TRUE;
}

gboolean handle_settings(GtkWidget *btn, gpointer window)
{
    GtkWidget *dialog = settings_dialog_new();
    gtk_widget_show_all(dialog);

    return TRUE;
}

TitleBar* title_bar_new(GtkWidget *window)
{
    TitleBar *title_bar = (TitleBar *)malloc(sizeof(TitleBar));
    GtkCssProvider *css_provider = gtk_css_provider_new();
    GtkBuilder *builder = gtk_builder_new_from_file("ui/title-bar.glade");
    title_bar->bar = (GtkWidget *)gtk_builder_get_object(builder, "title-bar");
    title_bar->search_input = (GtkWidget *)gtk_builder_get_object(builder, "search-input");
    title_bar->search_btn = (GtkWidget *)gtk_builder_get_object(builder, "search-btn");
    title_bar->settings_btn = (GtkWidget *)gtk_builder_get_object(builder, "settings-btn");

    gtk_css_provider_load_from_path(css_provider, "css/title-bar.css", NULL);
    gtk_style_context_add_provider_for_screen(
        (GdkScreen *) gtk_widget_get_screen(title_bar->bar),
        (GtkStyleProvider *)css_provider,
        GTK_STYLE_PROVIDER_PRIORITY_APPLICATION
    );
    g_signal_connect(window, "destroy", G_CALLBACK(window_destroy), title_bar);
    g_signal_connect(
        title_bar->search_btn,
        "activate-link",
        G_CALLBACK(handle_search),
        NULL
    );
    g_signal_connect(
        title_bar->settings_btn,
        "activate-link",
        G_CALLBACK(handle_settings),
        window
    );

    return title_bar;
}
