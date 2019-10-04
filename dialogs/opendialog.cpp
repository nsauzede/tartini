/***************************************************************************
                          opendialog.cpp  -  description
                             -------------------
    begin                : Feb 2005
    copyright            : (C) 2005 by Philip McLeod
    email                : pmcleod@cs.otago.ac.nz
   
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
#include "assert.h"

//------------------------------------------------------------------------------
OpenDialog::OpenDialog(QWidget * parent):
  QFileDialog(parent,tr("Open File"),QDir::toNativeSeparators(gdata->getSettingsValue("Dialogs/openFilesFolder",QDir::currentPath())),"Wave files (*.wav)")
{
  setWindowTitle("Choose a file to open");
  setFileMode(QFileDialog::ExistingFile);
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
QString OpenDialog::getOpenWavFileName(QWidget *parent)
{
  OpenDialog d(parent);
  if(d.exec() != QDialog::Accepted)
    {
      return QString();
    }
  QStringList l_selected_files = d.selectedFiles();
  assert(1 == l_selected_files.size());
  return l_selected_files[0];
}

// EOF
