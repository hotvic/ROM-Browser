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
#include "rombrowserdirs.h"


static gchar *user_config_dir             = NULL;
static gchar *user_cache_dir              = NULL;
static gchar *user_styles_dir             = NULL;
static gchar *user_plugins_dir            = NULL;
static gchar *rombrowser_data_dir         = NULL;
static gchar *rombrowser_locale_dir       = NULL;
static gchar *rombrowser_lib_dir          = NULL;
static gchar *rombrowser_plugins_dir      = NULL;
static gchar *rombrowser_plugins_data_dir = NULL;

void
rombrowser_dirs_init ()
{
#ifdef G_OS_WIN32
  gchar *win32_dir;

  win32_dir = g_win32_get_package_installation_directory_of_module (NULL);

  rombrowser_data_dir = g_build_filename (win32_dir,
                                          "share",
                                          "rombrowsser",
                                          NULL);
  rombrowser_locale_dir = g_build_filename (win32_dir,
                                            "share",
                                            "locale",
                                            NULL);
  rombrowser_lib_dir = g_build_filename (win32_dir,
                                         "lib",
                                         "rombrowser",
                                         NULL);

  g_free (win32_dir);
#else /* !G_OS_WIN32 */

  if (rombrowser_data_dir == NULL) {
    rombrowser_data_dir = g_build_filename (DATADIR,
                                            "rombrowser",
                                            NULL);
    rombrowser_locale_dir = g_build_filename (DATADIR,
                                              "locale",
                                              NULL);
    rombrowser_lib_dir = g_build_filename (LIBDIR,
                                           "rombrowser",
                                           NULL);
  }
#endif /* !G_OS_WIN32 */

  user_cache_dir = g_build_filename (g_get_user_cache_dir (),
                                     "rombrowser",
                                     NULL);
  user_config_dir = g_build_filename (g_get_user_config_dir (),
                                      "rombrowser",
                                      NULL);
}

void
rombrowser_dirs_shutdown ()
{
  g_free (user_config_dir);
  g_free (user_cache_dir);
  g_free (rombrowser_data_dir);
  g_free (rombrowser_locale_dir);
  g_free (rombrowser_lib_dir);
}

const gchar *
rombrowser_dirs_get_user_config_dir (void)
{
  return user_config_dir;
}

const gchar *
rombrowser_dirs_get_user_cache_dir (void)
{
  return user_cache_dir;
}

const gchar *
rombrowser_dirs_get_rombrowser_data_dir (void)
{
  return rombrowser_data_dir;
}

const gchar *
rombrowser_dirs_get_rombrowser_locale_dir (void)
{
  return rombrowser_locale_dir;
}

const gchar *
rombrowser_dirs_get_rombrowser_lib_dir (void)
{
  return rombrowser_lib_dir;
}

gchar *
rombrowser_dirs_get_ui_file (const gchar *file)
{
  gchar *ui_file;

  g_return_val_if_fail (file != NULL, NULL);

  ui_file = g_build_filename (rombrowser_dirs_get_rombrowser_data_dir (),
                              "ui",
                              file,
                              NULL);

  return ui_file;
}
