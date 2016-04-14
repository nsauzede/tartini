/***************************************************************************
                          opendialog.cpp  -  description
                             -------------------
    begin                : Feb 2005
    copyright            : (C) 2005 by Philip McLeod
    email                : pmcleod@cs.otago.ac.nz
    copyright            : (C) 2019 by Julien Thevenon
    email                : julien_thevenon at yahoo.fr

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   
   Please read LICENSE.txt for details.
 ***************************************************************************/

#include "opendialog.h"

#include <QLayout>
#include <QLabel>
#include <QCheckBox>
#include <QVBoxLayout>
#include "gdata.h"

//------------------------------------------------------------------------------
OpenDialog::OpenDialog(QWidget * p_parent)
: QFileDialog( p_parent
             , tr("Open File")
             , QDir::convertSeparators(g_data->getSettingsValue( "Dialogs/openFilesFolder"
                                                             , QDir::currentPath()
                                                             )
                                    )
             , "Wave files (*.wav)"
             )
{
  setCaption("Choose a file to open");
  setMode(QFileDialog::ExistingFile);
}

//------------------------------------------------------------------------------
OpenDialog::~OpenDialog(void)
{
}

//------------------------------------------------------------------------------
void OpenDialog::accept(void)
{
    QFileDialog::accept();
}

//------------------------------------------------------------------------------
QString OpenDialog::getOpenWavFileName(QWidget *p_parent)
{
    OpenDialog l_dialog(p_parent);
    if(l_dialog.exec() != QDialog::Accepted)
    {
        return QString();
    }
    return l_dialog.selectedFile();
}

// EOF
