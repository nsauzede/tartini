/***************************************************************************
                          summaryview.h  -  description
                             -------------------
    begin                : Fri Dec 10 2004
    copyright            : (C) 2004-2005 by Philip McLeod
    email                : pmcleod@cs.otago.ac.nz
    copyright            : (C) 2016 by Julien Thevenon
    email                : julien_thevenon at yahoo.fr
 
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   
   Please read LICENSE.txt for details.
 ***************************************************************************/
#ifndef SUMMARYVIEW_H
#define SUMMARYVIEW_H

#include "viewwidget.h"
#include <QResizeEvent>

class SummaryDrawWidget;

class SummaryView: public ViewWidget
{
  Q_OBJECT

  public:

    SummaryView(int p_view_id
               ,QWidget *p_parent = NULL
               );
    virtual ~SummaryView(void);

    void resizeEvent(QResizeEvent *);

    QSize sizeHint(void) const;

  private:

    SummaryDrawWidget * m_summary_draw_widget;
};
#endif // SUMMARYVIEW_H
// EOF

