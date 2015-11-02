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

#include <QTime>

#include "joker_card.h"
#include "joker_deck.h"

joker_deck::joker_deck(void)
{
  m_cards << new joker_card(joker_card::ACE_CLUBS);
  m_cards << new joker_card(joker_card::ACE_DIAMONDS);
  m_cards << new joker_card(joker_card::ACE_HEARTS);
  m_cards << new joker_card(joker_card::ACE_SPADES);
  m_cards << new joker_card(joker_card::EIGHT_CLUBS);
  m_cards << new joker_card(joker_card::EIGHT_DIAMONDS);
  m_cards << new joker_card(joker_card::EIGHT_HEARTS);
  m_cards << new joker_card(joker_card::EIGHT_SPADES);
  m_cards << new joker_card(joker_card::FIVE_CLUBS);
  m_cards << new joker_card(joker_card::FIVE_DIAMONDS);
  m_cards << new joker_card(joker_card::FIVE_HEARTS);
  m_cards << new joker_card(joker_card::FIVE_SPADES);
  m_cards << new joker_card(joker_card::FOUR_CLUBS);
  m_cards << new joker_card(joker_card::FOUR_DIAMONDS);
  m_cards << new joker_card(joker_card::FOUR_HEARTS);
  m_cards << new joker_card(joker_card::FOUR_SPADES);
  m_cards << new joker_card(joker_card::JACK_CLUBS);
  m_cards << new joker_card(joker_card::JACK_DIAMONDS);
  m_cards << new joker_card(joker_card::JACK_HEARTS);
  m_cards << new joker_card(joker_card::JACK_SPADES);
  m_cards << new joker_card(joker_card::JOKER_1);
  m_cards << new joker_card(joker_card::JOKER_2);
  m_cards << new joker_card(joker_card::KING_CLUBS);
  m_cards << new joker_card(joker_card::KING_DIAMONDS);
  m_cards << new joker_card(joker_card::KING_HEARTS);
  m_cards << new joker_card(joker_card::KING_SPADES);
  m_cards << new joker_card(joker_card::NINE_CLUBS);
  m_cards << new joker_card(joker_card::NINE_DIAMONDS);
  m_cards << new joker_card(joker_card::NINE_HEARTS);
  m_cards << new joker_card(joker_card::NINE_SPADES);
  m_cards << new joker_card(joker_card::QUEEN_CLUBS);
  m_cards << new joker_card(joker_card::QUEEN_DIAMONDS);
  m_cards << new joker_card(joker_card::QUEEN_HEARTS);
  m_cards << new joker_card(joker_card::QUEEN_SPADES);
  m_cards << new joker_card(joker_card::SEVEN_CLUBS);
  m_cards << new joker_card(joker_card::SEVEN_DIAMONDS);
  m_cards << new joker_card(joker_card::SEVEN_HEARTS);
  m_cards << new joker_card(joker_card::SEVEN_SPADES);
  m_cards << new joker_card(joker_card::SIX_CLUBS);
  m_cards << new joker_card(joker_card::SIX_DIAMONDS);
  m_cards << new joker_card(joker_card::SIX_HEARTS);
  m_cards << new joker_card(joker_card::SIX_SPADES);
  m_cards << new joker_card(joker_card::TEN_CLUBS);
  m_cards << new joker_card(joker_card::TEN_DIAMONDS);
  m_cards << new joker_card(joker_card::TEN_HEARTS);
  m_cards << new joker_card(joker_card::TEN_SPADES);
  m_cards << new joker_card(joker_card::THREE_CLUBS);
  m_cards << new joker_card(joker_card::THREE_DIAMONDS);
  m_cards << new joker_card(joker_card::THREE_HEARTS);
  m_cards << new joker_card(joker_card::THREE_SPADES);
  m_cards << new joker_card(joker_card::TWO_CLUBS);
  m_cards << new joker_card(joker_card::TWO_DIAMONDS);
  m_cards << new joker_card(joker_card::TWO_HEARTS);
  m_cards << new joker_card(joker_card::TWO_SPADES);
  shuffle();
}

joker_deck::~joker_deck(void)
{
  for(int i = 0; i < m_cards.size(); i++)
    delete m_cards[i];

  m_cards.clear();
}

void joker_deck::shuffle(void)
{
  qsrand(static_cast<uint> (QTime(0, 0, 0).secsTo(QTime::currentTime())));

  for(int i = 0; i < m_cards.size(); i++)
    {
      int index = qrand() % m_cards.size();
      joker_card *card1 = m_cards[i];
      joker_card *card2 = m_cards[index];

      m_cards.replace(i, card2);
      m_cards.replace(index, card1);
    }
}
