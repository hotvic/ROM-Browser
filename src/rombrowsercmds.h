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

#ifndef __ROMBROWSER_COMMANDS_H__
#define __ROMBROWSER_COMMANDS_H__
#include <gio/gio.h>
#include <gtk/gtk.h>

#include "rombrowserapp.h"
#include "rombrowsersettings.h"


G_BEGIN_DECLS

void _rombrowser_cmd_help_about    (GSimpleAction  *action,
                                    GtkWindow      *window,
                                    RomBrowserApp  *app);
void _rombrowser_cmd_file_quit     (GSimpleAction  *action,
                                    GtkWindow      *window,
                                    RomBrowserApp  *app);

G_END_DECLS

#endif /* __ROMBROWSER_COMMANDS_H__ */
