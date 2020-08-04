#include "tabheader.h"

enum {
    TAB_HEADER_SIGNAL,
    LAST_SIGNAL
};

static void tab_header_class_init(TabHeaderClass *);
static void tab_header_init(TabHeader *);
static gboolean handle_button_press(GtkWidget *, GdkEvent *, gpointer);

static guint tab_header_signals[LAST_SIGNAL] = { 0 };

GType tab_header_get_type()
{
    static GType th_type = 0;

    if (!th_type)
    {
        const GTypeInfo th_info = {
            sizeof(TabHeaderClass),
            NULL,
            NULL,
            (GClassInitFunc) tab_header_class_init,
            NULL,
            NULL,
            sizeof(TabHeader),
            0,
            (GInstanceInitFunc) tab_header_init
        };

        th_type = g_type_register_static(
            GTK_TYPE_BOX,
            "TabHeader",
            &th_info,
            0
        );
    }

    return th_type;
}

static void tab_header_class_init(TabHeaderClass *kclass)
{
    tab_header_signals[TAB_HEADER_SIGNAL] = g_signal_new(
        "tab-header-clicked",
        G_TYPE_FROM_CLASS(kclass),
        G_SIGNAL_RUN_FIRST | G_SIGNAL_ACTION,
        G_STRUCT_OFFSET(TabHeaderClass, tab_header),
        NULL,
        NULL,
        g_cclosure_marshal_VOID__VOID,
        G_TYPE_NONE,
        0
    );
}

static gboolean handle_button_press(GtkWidget *widget, GdkEvent *evt, gpointer user_data)
{
g_print("button press\n");
    return TRUE;
}

static void tab_header_init(TabHeader *th)
{
    GtkStyleContext *style_ctx;
    th->wrapper = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    th->event_box = gtk_event_box_new();
    th->close_btn = gtk_button_new();
    th->icon = gtk_image_new();
    th->title = gtk_label_new("哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈");
    th->spinner = gtk_spinner_new();
    style_ctx = gtk_widget_get_style_context(GTK_WIDGET(th));

    gtk_style_context_add_class(style_ctx, "tab-header-root");
    gtk_widget_set_name(th->close_btn, "closeTabBtn");
    gtk_widget_set_name(th->title, "tabTitle");
    gtk_widget_set_tooltip_text (th->title, "hhhh");

    gtk_container_add(GTK_CONTAINER(th), th->event_box);
    gtk_container_add(GTK_CONTAINER(th->event_box), th->wrapper);
    gtk_container_add(GTK_CONTAINER(th->wrapper), th->icon);
    gtk_container_add(GTK_CONTAINER(th->wrapper), th->spinner);
    gtk_container_add(GTK_CONTAINER(th->wrapper), th->title);
    gtk_container_add(GTK_CONTAINER(th->wrapper), th->close_btn);

    gtk_widget_set_size_request(GTK_WIDGET(th->wrapper), 200, -1);
    gtk_widget_set_halign(th->title, GTK_ALIGN_START);
    gtk_label_set_ellipsize(GTK_LABEL(th->title), PANGO_ELLIPSIZE_END);
    gtk_box_set_child_packing(GTK_BOX(th->wrapper), th->title, TRUE, TRUE, 0, GTK_PACK_START);
    gtk_label_set_max_width_chars((GtkLabel *)th->title, 15);
    gtk_widget_set_valign(th->icon, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(th->close_btn, GTK_ALIGN_CENTER);

    g_signal_connect(th->event_box, "button-press-event", G_CALLBACK(handle_button_press), NULL);
}

GtkWidget* tab_header_new()
{
    return GTK_WIDGET(g_object_new(TAB_HEADER_TYPE, NULL));
}

void tab_header_set_title(TabHeader *th, gchar *title)
{
    gtk_label_set_text(GTK_LABEL(th->title), title);
}

void tab_header_set_favicon(TabHeader *th, cairo_surface_t *img)
{
    gtk_image_set_from_surface(GTK_IMAGE(th->icon), img);
}

void tab_header_clear(TabHeader *th)
{

}
