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
#include <QGraphicsTextItem>
#include <QSettings>

#include "joker.h"
#include "joker_game.h"
#include "joker_graphicsitempixmap.h"

joker::joker(void):QMainWindow()
{
  m_game = 0;
  m_ui.setupUi(this);
  m_ui.view->setScene(new QGraphicsScene(this));
  connect(m_ui.actionQueens_Shuffle,
	  SIGNAL(triggered(void)),
	  this,
	  SLOT(slot_queens_shuffle(void)));
  connect(m_ui.action_Quit,
	  SIGNAL(triggered(void)),
	  this,
	  SLOT(slot_quit(void)));
  setWindowIcon(QIcon(":/joker.png"));
}

joker::~joker()
{
  delete m_game;
}

QString joker::home_path(void)
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

void joker::prepare_view(void)
{
  if(!m_game)
    return;

  m_ui.view->scene()->clear();

  int column_index = 0;
  int height = 200;
  int row_index = 0;
  int width = 142;

  /*
  ** Computer.
  */


  for(int i = 0; i < m_game->card_count(); i++)
    {
      auto pixmap_item = new joker_graphicsitempixmap
	(QPixmap(":/card_joker_theme.png").scaled(width,
						  height,
						  Qt::IgnoreAspectRatio,
						  Qt::SmoothTransformation),
	 0);

      if(row_index == 0)
	pixmap_item->setPos(width * column_index, 0);
      else
	pixmap_item->setPos(width * column_index, height * row_index);

      column_index += 1;
      m_ui.view->scene()->addItem(pixmap_item);
      pixmap_item->setFlag(QGraphicsItem::ItemIsSelectable, false);

      if(column_index >= m_game->card_count() / 2)
	{
	  row_index += 1;
	  column_index = 0;
	}
    }

  /*
  ** Player.
  */

  for(int i = 0; i < m_game->card_count(); i++)
    {
      auto pixmap_item = new joker_graphicsitempixmap
	(QPixmap(":/card_joker_theme.png").scaled(width,
						  height,
						  Qt::IgnoreAspectRatio,
						  Qt::SmoothTransformation),
	 0);
      auto text_item = new QGraphicsTextItem();

      pixmap_item->setPos(width * column_index, height * row_index);
      text_item->setPos(width * column_index, height * row_index);
      column_index += 1;
      m_ui.view->scene()->addItem(pixmap_item);
      m_ui.view->scene()->addItem(text_item);
      pixmap_item->setFlag(QGraphicsItem::ItemIsSelectable, true);
      text_item->setHtml(QString("<font size=10><b>%1</b></font>").arg(i + 1));

      if(column_index >= m_game->card_count() / 2)
	{
	  row_index += 1;
	  column_index = 0;
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

void joker::slot_queens_shuffle(void)
{
  delete m_game;
  m_game = new joker_game(joker_game::GameType::QUEENS_SHUFFLE);
  prepare_view();
}

void joker::slot_quit(void)
{
  close();
  QApplication::instance()->quit();
}
