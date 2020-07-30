#include "headerbar.h"
#include "widgets/tabheader.h"

Headerbar* create_headerbar(WebKitWebView *web_view)
{
    Headerbar *headerbar = (Headerbar *) malloc(sizeof(Headerbar));
    GtkBuilder *builder = gtk_builder_new_from_file("./ui/header-bar.ui");
    GtkButton *new_tab_btn = (GtkButton *)gtk_builder_get_object(builder, "new-tab-btn");

    headerbar->add_btn = new_tab_btn;
    headerbar->web_view = web_view;
    headerbar->bar = (GtkHeaderBar *)gtk_builder_get_object(builder, "header-bar");
    headerbar->tab_wrapper = (GtkBox *)gtk_builder_get_object(builder, "tab-wrapper");
    headerbar->titlebar = (GtkWidget *)gtk_builder_get_object(builder, "titlebar");

    gtk_container_add(GTK_CONTAINER(headerbar->tab_wrapper), tab_header_new());
    return headerbar;
}
