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

#ifndef __ROMBROWSER_DIRS_H__
#define __ROMBROWSER_DIRS_H__

#include <glib.h>

G_BEGIN_DECLS

/* This function must be called before starting rombrowser */
void         rombrowser_dirs_init                               (void);
/* This function must be called before exiting rombrowser */
void         rombrowser_dirs_shutdown                           (void);

const gchar *rombrowser_dirs_get_user_config_dir                (void);
const gchar *rombrowser_dirs_get_user_cache_dir                 (void);
const gchar *rombrowser_dirs_get_user_styles_dir                (void);
const gchar *rombrowser_dirs_get_user_plugins_dir               (void);
const gchar *rombrowser_dirs_get_rombrowser_data_dir            (void);
const gchar *rombrowser_dirs_get_rombrowser_locale_dir          (void);
const gchar *rombrowser_dirs_get_rombrowser_lib_dir             (void);
const gchar *rombrowser_dirs_get_rombrowser_plugins_dir         (void);
const gchar *rombrowser_dirs_get_rombrowser_plugins_data_dir    (void);

gchar       *rombrowser_dirs_get_ui_file                        (const gchar *file);

G_END_DECLS

#endif /* __ROMBROWSER_DIRS_H__ */
