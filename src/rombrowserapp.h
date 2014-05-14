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

#ifndef __ROMBROWSER_APP_H__
#define __ROMBROWSER_APP_H__

#include <glib.h>
#include <gio/gio.h>
#include <gtk/gtk.h>


G_BEGIN_DECLS

#define ROMBROWSER_TYPE_APP              (rombrowser_app_get_type())
#define ROMBROWSER_APP(obj)              (G_TYPE_CHECK_INSTANCE_CAST((obj),  ROMBROWSER_TYPE_APP, RomBrowserApp))
#define ROMBROWSER_APP_CONST(obj)        (G_TYPE_CHECK_INSTANCE_CAST ((obj), ROMBROWSER_TYPE_APP, RomBrowserSettings const))
#define ROMBROWSER_APP_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST((klass),   ROMBROWSER_TYPE_APP, RomBrowserAppClass))
#define ROMBROWSER_IS_APP(obj)           (G_TYPE_CHECK_INSTANCE_TYPE((obj),  ROMBROWSER_TYPE_APP))
#define ROMBROWSER_IS_APP_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass),  ROMBROWSER_TYPE_APP))
#define ROMBROWSER_APP_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS((obj),   ROMBROWSER_TYPE_APP, RomBrowserAppClass))

typedef struct _RomBrowserApp        RomBrowserApp;
typedef struct _RomBrowserAppClass   RomBrowserAppClass;
typedef struct _RomBrowserAppPrivate RomBrowserAppPrivate;

struct _RomBrowserApp
{
  GtkApplication parent;

  /*< private > */
  RomBrowserAppPrivate *priv;
};

struct _RomBrowserAppClass
{
  GtkApplicationClass parent_class;

  gboolean (*show_help)                    (RomBrowserApp   *app,
                                            GtkWindow   *parent,
                                            const gchar *name,
                                            const gchar *link_id);

  gchar *(*help_link_id)                   (RomBrowserApp    *app,
                                            const gchar *name,
                                            const gchar *link_id);
};


/* Public methods */
GType          rombrowser_app_get_type          (void) G_GNUC_CONST;

RomBrowserApp *rombrowser_app_new               (void);


G_END_DECLS

#endif  /* __ROMBROWSER_APP_H__  */
