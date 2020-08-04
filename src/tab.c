#include "tab.h"
#include <stdlib.h>

Tab* create_tab(WebKitWebView *related_web_view)
{
    Tab *tab = (Tab *)malloc(sizeof(Tab));
    tab->header = tab_header_new();

    if (related_web_view != NULL)
    {
        tab->web_view = webkit_web_view_new_with_related_view(related_web_view);
    }
    else
    {
        tab->web_view = webkit_web_view_new();
    }

    init_web_view_settings(tab->web_view);

    return tab;
}

void init_web_view_settings(WebKitWebView *web_view)
{
    WebKitSettings *settings = webkit_settings_new();
    webkit_settings_set_enable_smooth_scrolling(settings, TRUE);
    webkit_settings_set_enable_developer_extras(settings, TRUE);
    webkit_settings_set_user_agent_with_application_details(settings, "Chrome", "83");
    webkit_settings_set_javascript_can_access_clipboard(settings, TRUE);
    webkit_settings_set_javascript_can_open_windows_automatically(settings, TRUE);
    webkit_settings_set_allow_file_access_from_file_urls(settings, TRUE);
    webkit_settings_set_media_playback_allows_inline(settings, TRUE);
    webkit_web_view_set_settings(web_view, settings);
}

void load_page(GtkBuilder *builder, WebKitWebView *web_view, WebKitURIRequest *request)
{

    g_signal_connect(
        web_view,
        "load-changed",
        G_CALLBACK(handle_load_change),
        builder
    );
    webkit_web_view_load_request(web_view, request);
}

void handle_load_change(WebKitWebView *wv, WebKitLoadEvent evt, gpointer user_data)
{
    GtkBuilder *builder = (GtkBuilder *)user_data;
    GtkProgressBar *progress_bar = (GtkProgressBar *)gtk_builder_get_object(builder, "progressbar");

    switch(evt)
    {
    case WEBKIT_LOAD_STARTED:
        gtk_widget_set_opacity((GtkWidget *)progress_bar, 1);
        gtk_progress_bar_set_fraction(progress_bar, 0);
        break;
    case WEBKIT_LOAD_REDIRECTED:
        break;
    case WEBKIT_LOAD_COMMITTED:
        break;
    case WEBKIT_LOAD_FINISHED:
        g_timeout_add(300, (GSourceFunc)hide_progress_bar, progress_bar);
        break;
    }

    gtk_progress_bar_set_fraction(progress_bar, webkit_web_view_get_estimated_load_progress(wv));
}
