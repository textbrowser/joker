/*
** Copyright (c) 2015 - present, Alexis Megas.
** All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions
** are met
** 1. Redistributions of source code must retain the above copyright
**    notice, this list of conditions and the following disclaimer.
** 2. Redistributions in binary form must reproduce the above copyright
**    notice, this list of conditions and the following disclaimer in the
**    documentation and/or other materials provided with the distribution.
** 3. The name of the author may not be used to endorse or promote products
**    derived from Joker without specific prior written permission.
**
** JOKER IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
** IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
** OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
** IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
** INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
** NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
** JOKER, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef _joker_graphicsitempixmap_h_
#define _joker_graphicsitempixmap_h_

#include <QGraphicsPixmapItem>

class joker_graphicsitempixmap: public QGraphicsPixmapItem
{
 public:
  joker_graphicsitempixmap(const QPixmap &pixmap,
			   QGraphicsItem *parent):QGraphicsPixmapItem(pixmap,
								      parent)
  {
  }

  ~joker_graphicsitempixmap()
  {
  }

  void paint(QPainter *painter,
	     const QStyleOptionGraphicsItem *option,
	     QWidget *widget = 0)
  {
    Q_UNUSED(widget);

    if(!option || !painter)
      return;

    painter->setRenderHint(QPainter::SmoothPixmapTransform, true);

    QRectF exposed_rect(option->exposedRect.adjusted(-1, -1, 1, 1));

    exposed_rect &= QRectF(offset().x(), offset().y(),
			   pixmap().width(),
			   pixmap().height());
    painter->drawPixmap
      (exposed_rect, pixmap(), exposed_rect.translated(-offset()));

    if(!(option->state & (QStyle::State_Selected | QStyle::State_HasFocus)))
      return;

    const QRectF murect = painter->transform().mapRect(QRectF(0, 0, 1, 1));

    if(qFuzzyIsNull(qMax(murect.width(), murect.height())))
      return;

    const QRectF mbrect = painter->transform().mapRect(boundingRect());

    if(qMin(mbrect.width(), mbrect.height()) < qreal(1.0))
      return;

    const QColor bgcolor("#3E2723");
    const qreal pad = 0.0;
    const qreal pen_width = 2.5;

    painter->setPen(QPen(bgcolor, pen_width, Qt::SolidLine));
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(boundingRect().adjusted(pad, pad, -pad, -pad));
  }
};

#endif
