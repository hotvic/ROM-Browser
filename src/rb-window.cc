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
#include "rb-i18n.h"

#include "rb-window.hh"

#include <boost/filesystem.hpp>


using namespace RB;
namespace fs = boost::filesystem;

Window::Window(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder>& builder)
: Gtk::ApplicationWindow(cobject)
, m_refBuilder(builder)
{
    Glib::RefPtr<Gtk::Builder> mbuilder;

    mbuilder = Gtk::Builder::create_from_resource("/org/hotvic/rombrowser/ui/menu.ui");

    Glib::RefPtr<Gio::MenuModel> model = Glib::RefPtr<Gio::MenuModel>::cast_static(mbuilder->get_object("gearsmenu"));

    Gtk::MenuButton *gears;
    m_refBuilder->get_widget("gears", gears);
    gears->set_menu_model(model);

    /* Widgets */
    m_refBuilder->get_widget("romsTreeView", m_TreeView);

    m_TreeView->append_column(_("Name"), m_Columns.m_col_name);
    m_TreeView->append_column(_("File"), m_Columns.m_col_path);

    m_RomList = Gtk::TreeStore::create(m_Columns);
    m_TreeView->set_model(m_RomList);
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
