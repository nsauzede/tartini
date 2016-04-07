/***************************************************************************
                          savedialog.cpp  -  description
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

#include "savedialog.h"
#include <qcheckbox.h>
#include <qlayout.h>
#include <qlabel.h>
#include <QVBoxLayout>
#include "gdata.h"

//------------------------------------------------------------------------------
SaveDialog::SaveDialog(QWidget * parent):
  QFileDialog(parent,tr("Save file"),QDir::convertSeparators(gdata->getSettingsValue("Dialogs/saveFilesFolder", QDir::currentDirPath())),tr("Wave files (*.wav)"))
{
  setCaption(tr("Choose a filename to save under"));
  setAcceptMode(QFileDialog::AcceptSave);
  setFileMode(QFileDialog::AnyFile);
  setModal(true);
  setOption(QFileDialog::DontUseNativeDialog,true);
  QLayout * l_layout = this->layout();

  QVBoxLayout *baseLayout = new QVBoxLayout();
  l_layout->addItem(baseLayout);
  appendWavCheckBox =      new QCheckBox(tr("Append .wav extension if needed"), this);
  appendWavCheckBox->setChecked(gdata->getSettingsValue("Dialogs/appendWav", true));

  rememberFolderCheckBox = new QCheckBox(tr("Remember current folder"), this);
  rememberFolderCheckBox->setChecked(gdata->getSettingsValue("Dialogs/rememberSaveFolder", true));

  baseLayout->addSpacing(10);
  baseLayout->addWidget(appendWavCheckBox);
  baseLayout->addWidget(rememberFolderCheckBox);
}

//------------------------------------------------------------------------------
SaveDialog::~SaveDialog(void)
{
}

//------------------------------------------------------------------------------
void SaveDialog::accept(void)
{
  bool remember = rememberFolderCheckBox->isChecked();
  gdata->setSettingsValue("Dialogs/rememberSaveFolder", remember);
  if(remember == true)
    {
      QDir curDir = directory();
      gdata->setSettingsValue("Dialogs/saveFilesFolder", curDir.absPath());
    }
  bool appendWav = appendWavCheckBox->isChecked();
  gdata->setSettingsValue("Dialogs/appendWav", appendWav);
  if(appendWav == true)
    {
      QString s = selectedFile();
      if(!s.lower().endsWith(".wav"))
	{
	  s += ".wav";
	}
      selectFile(s);
    }
  QFileDialog::accept();
}

//------------------------------------------------------------------------------
QString SaveDialog::getSaveWavFileName(QWidget *parent)
{
  SaveDialog d(parent);
  if(d.exec() != QDialog::Accepted) return QString();
  return d.selectedFile();
}

// EOF
