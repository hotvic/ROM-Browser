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


#ifndef RB_WINDOW_H
#define RB_WINDOW_H

#include <gtkmm.h>


namespace RB
{

class Window : public Gtk::ApplicationWindow
{
public:
    Window(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder>& builder);
    virtual ~Window();
    static Glib::RefPtr<Window> create(Application *app);

protected:
    virtual void on_dispose();

    class ModelColumns : public Gtk::TreeModel::ColumnRecord
    {
    public:
        Gtk::TreeModelColumn<Glib::ustring> m_col_name;
        Gtk::TreeModelColumn<Glib::ustring> m_col_path;
        Gtk::TreeModelColumn<Glib::ustring> m_col_tooltip;

        ModelColumns()
        { add(m_col_name); add(m_col_path); add(m_col_tooltip); }
    };

    ModelColumns m_Columns;
    Glib::RefPtr<Gtk::Builder> m_refBuilder;
    Glib::RefPtr<Gtk::TreeStore> m_RomList;
    Gtk::TreeView *m_TreeView;
};

}

#endif /* RB_WINDOW_H */
