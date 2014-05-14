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
#include <string.h>

#include "rombrowsersettings.h"
#include "rombrowserapp.h"
#include "rombrowserdirs.h"


struct _RomBrowserSettingsPrivate
{
  GSettings *window_settings;
  GSettings *preferences;
  GSettings *emulators;
  GSettings *ui;
};

G_DEFINE_TYPE_WITH_PRIVATE (RomBrowserSettings, rombrowser_settings, G_TYPE_OBJECT)

static void
rombrowser_settings_finalize (GObject *object)
{
  RomBrowserSettings *rbs = ROMBROWSER_SETTINGS (object);

  G_OBJECT_CLASS (rombrowser_settings_parent_class)->finalize (object);
}

static void
rombrowser_settings_dispose (GObject *object)
{
  RomBrowserSettingsPrivate *priv = ROMBROWSER_SETTINGS (object)->priv;

  g_clear_object (&priv->window_settings);
  g_clear_object (&priv->preferences);
  g_clear_object (&priv->emulators);
  g_clear_object (&priv->ui);

  G_OBJECT_CLASS (rombrowser_settings_parent_class)->dispose (object);
}

static void
rombrowser_settings_init (RomBrowserSettings *rbs)
{
  rbs->priv = rombrowser_settings_get_instance_private (rbs);

  rbs->priv->window_settings = g_settings_new ("org.hotvic.rombrowser.state.window");
  rbs->priv->preferences = g_settings_new ("org.hotvic.rombrowser.preferences");
  rbs->priv->emulators = g_settings_new ("org.hotvic.rombrowser.preferences.emulators");
  rbs->priv->ui = g_settings_new ("org.hotvic.rombrowser.preferences.ui");
}

static void
rombrowser_settings_class_init (RomBrowserSettingsClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  object_class->finalize = rombrowser_settings_finalize;
  object_class->dispose = rombrowser_settings_dispose;
}

RomBrowserSettings *
rombrowser_settings_new ()
{
  return ROMBROWSER_SETTINGS (g_object_new (ROMBROWSER_TYPE_SETTINGS, NULL));
}
