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

#ifndef __ROMBROWSER_SETTINGS_H__
#define __ROMBROWSER_SETTINGS_H__

#include <gio/gio.h>
#include <glib-object.h>
#include <glib.h>
#include "rombrowserapp.h"

G_BEGIN_DECLS

#define ROMBROWSER_TYPE_SETTINGS            (rombrowser_settings_get_type ())
#define ROMBROWSER_SETTINGS(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), ROMBROWSER_TYPE_SETTINGS, RomBrowserSettings))
#define ROMBROWSER_SETTINGS_CONST(obj)      (G_TYPE_CHECK_INSTANCE_CAST ((obj), ROMBROWSER_TYPE_SETTINGS, RomBrowserSettings const))
#define ROMBROWSER_SETTINGS_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass),  ROMBROWSER_TYPE_SETTINGS, RomBrowserSettingsClass))
#define ROMBROWSER_IS_SETTINGS(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ROMBROWSER_TYPE_SETTINGS))
#define ROMBROWSER_IS_SETTINGS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass),  ROMBROWSER_TYPE_SETTINGS))
#define ROMBROWSER_SETTINGS_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj),  ROMBROWSER_TYPE_SETTINGS, RomBrowserSettingsClass))

typedef struct _RomBrowserSettings          RomBrowserSettings;
typedef struct _RomBrowserSettingsClass     RomBrowserSettingsClass;
typedef struct _RomBrowserSettingsPrivate   RomBrowserSettingsPrivate;

struct _RomBrowserSettings
{
  GObject parent;

  RomBrowserSettingsPrivate *priv;
};

struct _RomBrowserSettingsClass
{
  GObjectClass parent_class;
};

GType               rombrowser_settings_get_type    (void) G_GNUC_CONST;

RomBrowserSettings *rombrowser_settings_new         (void);

/* Utility functions */
GSList             *rombrowser_settings_get_list    (GSettings     *settings,
                                                     const gchar   *key);

void                rombrowser_settings_set_list    (GSettings     *settings,
                                                     const gchar   *key,
                                                     const GSList  *list);

/* key constants */
#define ROMBROWSER_SETTINGS_ONE_INSTANCE            "only-one-instance"

/* window state keys */
#define ROMBROWSER_SETTINGS_WINDOW_STATE            "state"
#define ROMBROWSER_SETTINGS_WINDOW_SIZE             "size"

G_END_DECLS

#endif /* __ROMBROWSER_SETTINGS_H__ */
