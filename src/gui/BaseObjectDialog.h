/* 

                          Firewall Builder

                 Copyright (C) 2009 NetCitadel, LLC

  Author:  Vadim Kurland     vadim@fwbuilder.org

  $Id$

  This program is free software which we release under the GNU General Public
  License. You may redistribute and/or modify this program under the terms
  of that license as published by the Free Software Foundation; either
  version 2 of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
 
  To get a copy of the GNU General Public License, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*/


#ifndef  __BASEOBJECTDIALOG_H_
#define  __BASEOBJECTDIALOG_H_

#include "fwbuilder/FWObject.h"
#include <QWidget>

class ProjectPanel;

class BaseObjectDialog : public QWidget
{
    Q_OBJECT;

protected:
    libfwbuilder::FWObject *obj;
    bool init;
    ProjectPanel *m_project;

public slots:

    virtual void changed()
    {
        if (!init)
        {
            emit changed_sign();
        }
    }

public:
    BaseObjectDialog(QWidget *parent) : QWidget(parent)
    {
        obj = 0;
        init = false;
        m_project = NULL;
    }
    virtual ~BaseObjectDialog() {};

    void attachToProjectWindow(ProjectPanel *pp) { m_project = pp; }
    ProjectPanel* getAssociatedProjectWindow() { return m_project; }

signals:
    void changed_sign();

};

#endif
