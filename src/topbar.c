#include "topbar.h"

Topbar* create_topbar(GtkWindow *window)
{
    Topbar topbar = {};
    Topbar *topbar_ptr = &topbar;
    GtkBuilder *builder = gtk_builder_new_from_file("./ui/page.ui");
    GtkBox *root_box = (GtkBox *)gtk_builder_get_object(builder, "root-box");
    GtkButton *back_btn = (GtkButton *)gtk_builder_get_object(builder, "back-btn");
    GtkButton *forward_btn = (GtkButton *)gtk_builder_get_object(builder, "forward-btn");
    GtkButton *refresh_btn = (GtkButton *)gtk_builder_get_object(builder, "refresh-btn");
    GtkButton *menu_btn = (GtkButton *)gtk_builder_get_object(builder, "menu-btn");
    gtk_button_set_image(back_btn, gtk_image_new_from_file("./assets/back.png"));
    gtk_button_set_image(forward_btn, gtk_image_new_from_file("./assets/forward.png"));
    gtk_button_set_image(refresh_btn, gtk_image_new_from_file("./assets/refresh.png"));
    gtk_button_set_image(menu_btn, gtk_image_new_from_file("./assets/menu.png"));

    topbar.root = root_box;
    topbar.back_btn = back_btn;
    topbar.forward_btn = forward_btn;
    topbar.refresh_btn = refresh_btn;
    topbar.menu_btn = menu_btn;
    topbar.progress_bar =  (GtkProgressBar *)gtk_builder_get_object(builder, "progressbar");
    topbar.parent_window = window;

    return topbar_ptr;
}
