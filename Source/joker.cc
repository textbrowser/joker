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

#include <QDir>
#include <QGraphicsScene>
#include <QSettings>

#include "joker.h"
#include "joker_game.h"
#include "joker_graphicsitempixmap.h"

joker::joker(void):QMainWindow()
{
  m_game = 0;
  m_ui.setupUi(this);
  m_ui.view->setScene(new QGraphicsScene(this));
  connect(m_ui.actionJumping_Jacks,
	  SIGNAL(triggered(void)),
	  this,
	  SLOT(slotJumpingJacks(void)));
  connect(m_ui.actionQueens_Shuffle,
	  SIGNAL(triggered(void)),
	  this,
	  SLOT(slotQueensShuffle(void)));
  connect(m_ui.action_Quit,
	  SIGNAL(triggered(void)),
	  this,
	  SLOT(slotQuit(void)));
}

joker::~joker()
{
  delete m_game;
}

QString joker::homePath(void)
{
#ifdef Q_OS_WIN32
  return QDir::currentPath() + QDir::separator() + ".joker.d";
#else
  return QDir::homePath() + QDir::separator() + ".joker.d";
#endif
}

void joker::closeEvent(QCloseEvent *event)
{
  QSettings settings;

  settings.setValue("geometry", saveGeometry());
  settings.setValue("state", saveState());
  QMainWindow::closeEvent(event);
}

void joker::prepareView(void)
{
  if(!m_game)
    return;

  m_ui.view->scene()->clear();

  int columnIndex = 0;
  int rowIndex = 0;

  for(int i = 0; i < m_game->cardCount(); i++)
    {
      joker_graphicsitempixmap *pixmapItem = new joker_graphicsitempixmap
	(QPixmap(":/joker.png").
	 scaled(126, 187, Qt::KeepAspectRatio, Qt::SmoothTransformation), 0);

      if(rowIndex == 0)
	pixmapItem->setPos(130 * columnIndex, 0);
      else
	pixmapItem->setPos(130 * columnIndex, 150 * rowIndex);

      columnIndex += 1;
      m_ui.view->scene()->addItem(pixmapItem);
      pixmapItem->setFlag(QGraphicsItem::ItemIsSelectable, true);

      if(columnIndex >= m_game->cardCount() / 2)
	{
	  rowIndex += 1;
	  columnIndex = 0;
	}
    }

  m_ui.view->scene()->setSceneRect(m_ui.view->scene()->itemsBoundingRect());
}

void joker::show(void)
{
  QSettings settings;

  restoreGeometry(settings.value("geometry").toByteArray());
  restoreState(settings.value("state").toByteArray());
  QMainWindow::show();
}

void joker::slotJumpingJacks(void)
{
  delete m_game;
  m_game = new joker_game(joker_game::JUMPING_JACKS);
  prepareView();
}

void joker::slotQueensShuffle(void)
{
  delete m_game;
  m_game = new joker_game(joker_game::QUEENS_SHUFFLE);
  prepareView();
}

void joker::slotQuit(void)
{
  close();
  QApplication::instance()->quit();
}
