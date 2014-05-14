/*
 * This file is part of ROM Browser.
 *
 * Copyright (C) 2014 Victor A. Santos <victoraur.santos@gmail.com>
 *
 * ROM Browser is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * ROM Browser is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <config.h>
#include <locale.h>
#include <libintl.h>

#include <gtk/gtk.h>

#include "rombrowserapp.h"
#include "rombrowserappwindow.h"
#include "rombrowserdirs.h"
#include "rombrowsercmds.h"


struct _RomBrowserAppPrivate
{
  RomBrowserSettings *settings;

  GMenuModel         *window_menu;
};

G_DEFINE_TYPE_WITH_PRIVATE (RomBrowserApp, rombrowser_app, GTK_TYPE_APPLICATION)

static gboolean
rombrowser_app_has_app_menu (RomBrowserApp *app)
{
  GtkSettings *gtk_settings;
  gboolean show_app_menu;
  gboolean show_menubar;

  /* We have three cases:
   * - GNOME 3: show-app-menu true, show-menubar false -> use the app menu
   * - Unity, OSX: show-app-menu and show-menubar true -> use the normal menu
   * - Other WM, Windows: show-app-menu and show-menubar false -> use the normal menu
   */
  gtk_settings = gtk_settings_get_default ();
  g_object_get (G_OBJECT (gtk_settings),
                "gtk-shell-shows-app-menu", &show_app_menu,
                "gtk-shell-shows-menubar", &show_menubar,
                NULL);

  return show_app_menu && !show_menubar;
}

static void
rombrowser_app_dispose (GObject *object)
{
  RomBrowserApp *app = ROMBROWSER_APP (object);

  g_clear_object (&app->priv->settings);

  G_OBJECT_CLASS (rombrowser_app_parent_class)->dispose (object);
}

static void
preferences_activated (GSimpleAction  *action,
                       GVariant       *parameter,
                       gpointer        user_data)
{
  GtkApplication *app;
  GtkApplicationWindow *window;

  app = GTK_APPLICATION (user_data);
  window = GTK_APPLICATION_WINDOW (gtk_application_get_active_window (app));

  //rombrowser_show_preferences_dialog (window);
}

static void
about_activated (GSimpleAction  *action,
                 GVariant       *parameter,
                 gpointer        user_data)
{
  GtkApplication *app;
  GtkApplicationWindow *window;

  app = GTK_APPLICATION (user_data);
  window = GTK_APPLICATION_WINDOW (gtk_application_get_active_window (app));

  _rombrowser_cmd_help_about (action, GTK_WINDOW (window), user_data);
}

static void
quit_activated (GSimpleAction *action,
                GVariant      *parameter,
                gpointer       user_data)
{
  GtkApplication *app;
  GtkApplicationWindow *window;

  app = GTK_APPLICATION (user_data);
  window = GTK_APPLICATION_WINDOW (gtk_application_get_active_window (app));

  _rombrowser_cmd_file_quit (action, GTK_WINDOW (window), ROMBROWSER_APP (app));
}

static GActionEntry app_entries[] = {
    { "prefs", preferences_activated, NULL, NULL, NULL },
    { "about", about_activated, NULL, NULL, NULL },
    { "quit", quit_activated, NULL, NULL, NULL }
};

static void
rombrowser_app_startup (GApplication *application)
{
  RomBrowserApp *app = ROMBROWSER_APP (application);
  const gchar *dir;
  gchar *icon_dir;
  GError *error = NULL;
  GtkBuilder *builder;

  G_APPLICATION_CLASS (rombrowser_app_parent_class)->startup (application);

  rombrowser_dirs_init ();

  /* Setup locale/gettext */
  setlocale (LC_ALL, "");

  dir = rombrowser_dirs_get_rombrowser_locale_dir ();
  bindtextdomain (PACKAGE, dir);

  bind_textdomain_codeset (PACKAGE, "UTF-8");
  textdomain (PACKAGE);

  /* Load settings */
  app->priv->settings = rombrowser_settings_new ();

  /* add actions */
  g_action_map_add_action_entries (G_ACTION_MAP(application),
                                   app_entries,
                                   G_N_ELEMENTS (app_entries),
                                   app);

  /* load menu model */
  builder = gtk_builder_new ();
  if (!gtk_builder_add_from_resource (builder,
                                      "/org/hotvic/rombrowser/ui/menu.ui",
                                      &error))
  {
    g_warning ("loading menu builder file: %s", error->message);
    g_error_free (error);
  } else {
    if (rombrowser_app_has_app_menu (app))
    {
      GMenuModel *appmenu;

      appmenu = G_MENU_MODEL (gtk_builder_get_object (builder, "appmenu"));
      gtk_application_set_app_menu (GTK_APPLICATION (application), appmenu);
    }
  }
  app->priv->window_menu = G_MENU_MODEL (gtk_builder_get_object(builder, "menubar"));

  g_object_unref (builder);
}

static void
rombrowser_app_activate (GApplication *application)
{
  GtkApplicationWindow *window = NULL;
  GMenuModel *gearmenu;

  window = rombrowser_app_window_new (ROMBROWSER_APP (application));

  //gtk_application_add_window (GTK_APPLICATION(application),
  //                            GTK_WINDOW(window));

  /* The gear nenu */
  //gearmenu = G_MENU_MODEL (gtk_builder_get_object (builder, "gearmenu"));

  gtk_widget_show_all(GTK_WIDGET (window));
}

static void
rombrowser_app_shutdown (GApplication *app)
{
  /* Last window is gone... save some settings and exit */
  //ensure_user_config_dir ();

  rombrowser_dirs_shutdown ();

  G_APPLICATION_CLASS (rombrowser_app_parent_class)->shutdown (app);
}

static void
rombrowser_app_class_init (RomBrowserAppClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  GApplicationClass *app_class = G_APPLICATION_CLASS (klass);

  object_class->dispose = rombrowser_app_dispose;

  app_class->startup = rombrowser_app_startup;
  app_class->activate = rombrowser_app_activate;
  app_class->shutdown = rombrowser_app_shutdown;
}

static void
rombrowser_app_init (RomBrowserApp *app)
{
  app->priv = rombrowser_app_get_instance_private (app);

  g_set_application_name ("rombrowser");
}


RomBrowserApp *
rombrowser_app_new(void)
{
  return g_object_new (ROMBROWSER_TYPE_APP,
                       "application-id", "org.hotvic.rombrowser",
                       NULL);
}
