#include "topbar.h"

Topbar* create_topbar()
{
    Topbar *topbar = (Topbar *) malloc(sizeof(Topbar));
    GtkBuilder *builder = gtk_builder_new_from_file("./ui/top-bar.ui");
    GtkButton *back_btn = (GtkButton *)gtk_builder_get_object(builder, "back-btn");
    GtkButton *forward_btn = (GtkButton *)gtk_builder_get_object(builder, "forward-btn");
    GtkButton *refresh_btn = (GtkButton *)gtk_builder_get_object(builder, "refresh-btn");
    GtkButton *menu_btn = (GtkButton *)gtk_builder_get_object(builder, "menu-btn");
    gtk_button_set_image(back_btn, gtk_image_new_from_file("./assets/back.png"));
    gtk_button_set_image(forward_btn, gtk_image_new_from_file("./assets/forward.png"));
    gtk_button_set_image(refresh_btn, gtk_image_new_from_file("./assets/refresh.png"));
    gtk_button_set_image(menu_btn, gtk_image_new_from_file("./assets/menu.png"));

    topbar->back_btn = back_btn;
    topbar->forward_btn = forward_btn;
    topbar->refresh_btn = refresh_btn;
    topbar->menu_btn = menu_btn;
    topbar->url_input = (GtkEntry *)gtk_builder_get_object(builder, "url-input");
    topbar->root = (GtkBox *)gtk_builder_get_object(builder, "top-root-box");

    return topbar;
}

void handle_back(GtkButton *btn, gpointer web_view)
{
    WebKitWebView *wv = (WebKitWebView *)web_view;

    if (webkit_web_view_can_go_back(wv))
    {
        webkit_web_view_go_back(wv);
    }
}

void handle_forward(GtkButton *btn, gpointer web_view)
{
    WebKitWebView *wv = (WebKitWebView *)web_view;

    if (webkit_web_view_can_go_forward(wv))
    {
        webkit_web_view_go_forward(wv);
    }
}

void handle_refresh(GtkButton *btn, gpointer web_view)
{
    webkit_web_view_reload((WebKitWebView *)web_view);
}

void handle_press_enter(GtkEntry *entry, gpointer web_view)
{
    WebKitWebView *wv = (WebKitWebView *) web_view;
    const char *text = gtk_entry_get_text(entry);


}
