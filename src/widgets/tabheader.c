#include "tabheader.h"

enum {
    TAB_HEADER_SIGNAL,
    LAST_SIGNAL
}

static void tab_header_class_init(TabHeaderClass *);
static void tab_header_init(TabHeader *);

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

static void tab_header_init(TabHeader *th)
{
    th->event_box = gtk_event_box_new();
    th->close_btn = gtk_button_new();
    th->icon = gtk_image_new();
    th->title = gtk_label_new("");

    gtk_container_add(GTK_CONTAINER(th), th->event_box);
    gtk_container_add(GTK_CONTAINER(th->event_box), th->icon);
    gtk_container_add(GTK_CONTAINER(th->event_box), th->title);
    gtk_container_add(GTK_CONTAINER(th->event_box), th->close_btn);
}

GtkWidget* tab_header_new()
{
    return GTK_WIDGET(g_object_new(TAB_HEADER_TYPE, NULL));
}

void tab_header_clear()
{

}
