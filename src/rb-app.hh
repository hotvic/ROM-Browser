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


#ifndef RB_APP_H
#define RB_APP_H

#include <gtkmm.h>


namespace RB
{

class Application : public Gtk::Application
{
protected:
    Application();

public:
    static Glib::RefPtr<Application> create();

protected:
    // Signal handlers
    virtual void on_startup();
    virtual void on_activate();

    Glib::RefPtr<Gio::Settings> preferences;

private:
    gboolean has_app_menu();

    void on_activate_preferences();
    void on_activate_about();
    void on_activate_quit();
};

}

#endif /* RB_APP_H */
