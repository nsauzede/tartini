/***************************************************************************
                          htrackview.h  -  description
                             -------------------
    begin                : 29 Mar 2005
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
#ifndef HTRACKVIEW_H
#define HTRACKVIEW_H

#include "viewwidget.h"
#include <QResizeEvent>

class HTrackWidget;
class QSlider;
class QwtWheel;

class HTrackView : public ViewWidget
{
  Q_OBJECT

  public:
    HTrackView(int viewID_, QWidget *parent = NULL);
    virtual ~HTrackView(void);

    void resizeEvent(QResizeEvent *);

    QSize sizeHint(void) const
    {
      return QSize(500, 400);
    }

  public slots:
    void setPeakThreshold(int value);

  private:
    HTrackWidget *hTrackWidget;
    QSlider *peakThresholdSlider;
    QwtWheel *rotateXWheel;
    QwtWheel *rotateYWheel;
    QwtWheel *distanceWheel;
};
#endif // HTRACKVIEW_H
// EOF
