/***************************************************************************
                          correlationwidget.h  -  description
                             -------------------
    begin                : May 2 2005
    copyright            : (C) 2005 by Philip McLeod
    email                : pmcleod@cs.otago.ac.nz
    copyright            : (C) 2016 by Julien Thevenon
    email                : julien_thevenon at yahoo.fr
 
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   
   Please read LICENSE.txt for details.
***************************************************************************/
#ifndef CORRELATIONWIDGET_H
#define CORRELATIONWIDGET_H

#include "drawwidget.h"
#include <QPolygon>
#include <QPaintEvent>
#include "array1d.h"

class CorrelationWidget : public DrawWidget
{
  Q_OBJECT

 public:
  CorrelationWidget(QWidget *parent);
  virtual ~CorrelationWidget(void);

  void paintEvent( QPaintEvent * );

  QSize sizeHint(void) const;

 private:
  QPolygon pointArray;
  Array1d<float> lookup;
  int aggregateMode;

  public slots:
  void setAggregateMode(int mode);
};
#endif // CORRELATIONWIDGET_H
// EOF

