#ifndef _TOPBAR_H
#define _TOPBAR_H
#endif // _TOPBAR_H

#include <gtk/gtk.h>

typedef struct topbar {
    GtkBox *root;
    GtkButton *back_btn;
    GtkButton *forward_btn;
    GtkButton *refresh_btn;
    GtkButton *url_input;
    GtkButton *menu_btn;
    GtkProgressBar *progress_bar;
    GtkWindow *parent_window;
} Topbar;

void handle_back(GtkButton *, gpointer);
void handle_forward(GtkButton *, gpointer);
void handle_refresh(GtkButton *, gpointer);
void handle_press_enter(GtkEntry *, gpointer);
void handle_menu(GtkButton *, gpointer);
Topbar* create_topbar(GtkWindow *);
