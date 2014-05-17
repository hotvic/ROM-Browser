#include "rombrowserapp.h"
#include "rombrowserappwindow.h"
#include <gtk/gtk.h>

struct _RomBrowserAppWindow
{
  GtkApplicationWindow parent;
};

struct _RomBrowserAppWindowClass
{
  GtkApplicationWindowClass parent_class;
};

typedef struct _RomBrowserAppWindowPrivate RomBrowserAppWindowPrivate;

struct _RomBrowserAppWindowPrivate
{
  GSettings     *settings;
  GtkMenuButton *gears;
  GtkWidget     *search;
  GtkWidget     *searchbar;
};

G_DEFINE_TYPE_WITH_PRIVATE(RomBrowserAppWindow, rombrowser_app_window, GTK_TYPE_APPLICATION_WINDOW);

static void
search_text_changed (GtkEntry *entry)
{
  RomBrowserAppWindow *win;
  RomBrowserAppWindowPrivate *priv;
  const gchar *text;

  text = gtk_entry_get_text (entry);

  if (text[0] == '\0')
    return;

  win = ROMBROWSER_APP_WINDOW (gtk_widget_get_toplevel (GTK_WIDGET (entry)));
  priv = rombrowser_app_window_get_instance_private (win);
}

const GActionEntry gearsaction[] = {
  {"run-selected", NULL}
};


static void
rombrowser_app_window_init (RomBrowserAppWindow *win)
{
  RomBrowserAppWindowPrivate *priv;
  GMenuModel *gearsmenu;
  GtkBuilder *builder;

  priv = rombrowser_app_window_get_instance_private (win);
  gtk_widget_init_template (GTK_WIDGET (win));
  priv->settings =  g_settings_new ("org.hotvic.rombrowser.preferences.ui");
  
  g_object_bind_property (priv->search, "active",
                          priv->searchbar, "search-mode-enabled",
                          G_BINDING_BIDIRECTIONAL
                          );

  builder = gtk_builder_new_from_resource ("/org/hotvic/rombrowser/ui/menu.ui");
  gearsmenu = G_MENU_MODEL (gtk_builder_get_object (builder, "gearsmenu"));
  gtk_menu_button_set_menu_model (priv->gears, gearsmenu);

  /* Actions */
  g_action_map_add_action_entries (G_ACTION_MAP (win), gearsaction,
                                   G_N_ELEMENTS (gearsaction), win);
}

static void
rombrowser_app_window_dispose (GObject *object)
{
  RomBrowserAppWindow *win;
  RomBrowserAppWindowPrivate *priv;

  win = ROMBROWSER_APP_WINDOW (object);
  priv = rombrowser_app_window_get_instance_private (win);

  g_clear_object (&priv->settings);

  G_OBJECT_CLASS (rombrowser_app_window_parent_class)->dispose (object);
}

static void
rombrowser_app_window_class_init (RomBrowserAppWindowClass *class)
{
  G_OBJECT_CLASS (class)->dispose = rombrowser_app_window_dispose;

  gtk_widget_class_set_template_from_resource (GTK_WIDGET_CLASS (class),
                                               "/org/hotvic/rombrowser/ui/rbmw.ui");

  gtk_widget_class_bind_template_child_private (GTK_WIDGET_CLASS (class), RomBrowserAppWindow, gears);
  gtk_widget_class_bind_template_child_private (GTK_WIDGET_CLASS (class), RomBrowserAppWindow, search);
  gtk_widget_class_bind_template_child_private (GTK_WIDGET_CLASS (class), RomBrowserAppWindow, searchbar);

  gtk_widget_class_bind_template_callback (GTK_WIDGET_CLASS (class), search_text_changed);
}

RomBrowserAppWindow *
rombrowser_app_window_new (RomBrowserApp *app)
{
  return g_object_new (ROMBROWSER_APP_WINDOW_TYPE, "application", app, NULL);
}
