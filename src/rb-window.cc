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


using namespace RB;

Window::Window(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder>& builder)
: Gtk::ApplicationWindow(cobject)
, m_refBuilder(builder)
{
    Glib::RefPtr<Gtk::Builder> mbuilder;
    Glib::RefPtr<Gio::MenuModel> model;
    Gtk::MenuButton *gears;

    mbuilder = Gtk::Builder::create_from_resource("/org/hotvic/rombrowser/ui/menu.ui");
    model = Glib::RefPtr<Gio::MenuModel>::cast_static(mbuilder->get_object("gearsmenu"));

    m_refBuilder->get_widget("gears", gears);
    gears->set_menu_model(model);
}

Window::~Window()
{
}

Glib::RefPtr<Window>
Window::create(Application *app)
{
    Glib::RefPtr<Gtk::Builder> builder;
    Window *window;

    builder = Gtk::Builder::create_from_resource("/org/hotvic/rombrowser/ui/window.ui");
    if (builder) {
        builder->get_widget_derived("RomBrowserAppWindow", window);

        app->add_window (*window);
    }

    return Glib::RefPtr<Window>(window);
}

void
Window::on_dispose()
{

}
