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


#include "rb-app.hh"

#include "rb-window.hh"
#include "rb-settings.hh"

using namespace RB;

Application::Application()
: Gtk::Application("org.hotvic.rombrowser")
{
    Glib::set_application_name("Rom Browser");

    preferences = Gio::Settings::create("org.hotvic.rombrowser.preferences");
}

Glib::RefPtr<Application>
Application::create()
{
    return Glib::RefPtr<Application> (new Application());
}

gboolean
Application::has_app_menu()
{
    Glib::RefPtr<Gtk::Settings> settings;
    gboolean show_app_menu;
    gboolean show_menubar;

    settings = Gtk::Settings::get_default();

    settings->get_property<gboolean>("gtk-shell-shows-app-menu", show_app_menu);
    settings->get_property<gboolean>("gtk-shell-shows-menubar", show_menubar);

    return show_app_menu && !show_menubar;
}

void
Application::on_startup()
{
    Glib::RefPtr<Gtk::Builder> builder;

    // Call the base class's implementation:
    Gtk::Application::on_startup();

    add_action ("preferences",
                sigc::mem_fun(*this, &Application::on_activate_preferences));
    add_action ("about",
                sigc::mem_fun(*this, &Application::on_activate_about));
    add_action ("quit",
                sigc::mem_fun(*this, &Application::on_activate_quit));

    builder = Gtk::Builder::create_from_resource("/org/hotvic/rombrowser/ui/menu.ui");

    if (has_app_menu())
    {
        Glib::RefPtr<Gio::MenuModel> model;

        builder->get_object("app_menu");

        set_app_menu(model);
    }
}

void
Application::on_activate()
{
    Glib::RefPtr<Window> window;

    if (this->preferences->get_boolean(RB_SETTINGS_ONE_INSTANCE))
        window = Glib::RefPtr<Window>((Window *) get_active_window());

    if (!window)
    {
        window = Window::create(this);
        window->show_all();
    }

    window->present();
}

void
Application::on_activate_preferences()
{

}

void
Application::on_activate_about()
{

}

void
Application::on_activate_quit()
{
    std::vector<Gtk::Window*> windows;

    windows = get_windows();

    for (std::vector<Gtk::Window*>::iterator it = windows.begin();
            it != windows.end(); it++)
    {
        (*it)->hide();
    }
}
