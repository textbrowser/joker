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

#include <QRandomGenerator>
#include <QTime>

#include "joker_card.h"
#include "joker_deck.h"

joker_deck::joker_deck(void)
{
  m_cards << new joker_card(joker_card::Type::ACE_CLUBS);
  m_cards << new joker_card(joker_card::Type::ACE_DIAMONDS);
  m_cards << new joker_card(joker_card::Type::ACE_HEARTS);
  m_cards << new joker_card(joker_card::Type::ACE_SPADES);
  m_cards << new joker_card(joker_card::Type::EIGHT_CLUBS);
  m_cards << new joker_card(joker_card::Type::EIGHT_DIAMONDS);
  m_cards << new joker_card(joker_card::Type::EIGHT_HEARTS);
  m_cards << new joker_card(joker_card::Type::EIGHT_SPADES);
  m_cards << new joker_card(joker_card::Type::FIVE_CLUBS);
  m_cards << new joker_card(joker_card::Type::FIVE_DIAMONDS);
  m_cards << new joker_card(joker_card::Type::FIVE_HEARTS);
  m_cards << new joker_card(joker_card::Type::FIVE_SPADES);
  m_cards << new joker_card(joker_card::Type::FOUR_CLUBS);
  m_cards << new joker_card(joker_card::Type::FOUR_DIAMONDS);
  m_cards << new joker_card(joker_card::Type::FOUR_HEARTS);
  m_cards << new joker_card(joker_card::Type::FOUR_SPADES);
  m_cards << new joker_card(joker_card::Type::JACK_CLUBS);
  m_cards << new joker_card(joker_card::Type::JACK_DIAMONDS);
  m_cards << new joker_card(joker_card::Type::JACK_HEARTS);
  m_cards << new joker_card(joker_card::Type::JACK_SPADES);
  m_cards << new joker_card(joker_card::Type::JOKER_1);
  m_cards << new joker_card(joker_card::Type::JOKER_2);
  m_cards << new joker_card(joker_card::Type::KING_CLUBS);
  m_cards << new joker_card(joker_card::Type::KING_DIAMONDS);
  m_cards << new joker_card(joker_card::Type::KING_HEARTS);
  m_cards << new joker_card(joker_card::Type::KING_SPADES);
  m_cards << new joker_card(joker_card::Type::NINE_CLUBS);
  m_cards << new joker_card(joker_card::Type::NINE_DIAMONDS);
  m_cards << new joker_card(joker_card::Type::NINE_HEARTS);
  m_cards << new joker_card(joker_card::Type::NINE_SPADES);
  m_cards << new joker_card(joker_card::Type::QUEEN_CLUBS);
  m_cards << new joker_card(joker_card::Type::QUEEN_DIAMONDS);
  m_cards << new joker_card(joker_card::Type::QUEEN_HEARTS);
  m_cards << new joker_card(joker_card::Type::QUEEN_SPADES);
  m_cards << new joker_card(joker_card::Type::SEVEN_CLUBS);
  m_cards << new joker_card(joker_card::Type::SEVEN_DIAMONDS);
  m_cards << new joker_card(joker_card::Type::SEVEN_HEARTS);
  m_cards << new joker_card(joker_card::Type::SEVEN_SPADES);
  m_cards << new joker_card(joker_card::Type::SIX_CLUBS);
  m_cards << new joker_card(joker_card::Type::SIX_DIAMONDS);
  m_cards << new joker_card(joker_card::Type::SIX_HEARTS);
  m_cards << new joker_card(joker_card::Type::SIX_SPADES);
  m_cards << new joker_card(joker_card::Type::TEN_CLUBS);
  m_cards << new joker_card(joker_card::Type::TEN_DIAMONDS);
  m_cards << new joker_card(joker_card::Type::TEN_HEARTS);
  m_cards << new joker_card(joker_card::Type::TEN_SPADES);
  m_cards << new joker_card(joker_card::Type::THREE_CLUBS);
  m_cards << new joker_card(joker_card::Type::THREE_DIAMONDS);
  m_cards << new joker_card(joker_card::Type::THREE_HEARTS);
  m_cards << new joker_card(joker_card::Type::THREE_SPADES);
  m_cards << new joker_card(joker_card::Type::TWO_CLUBS);
  m_cards << new joker_card(joker_card::Type::TWO_DIAMONDS);
  m_cards << new joker_card(joker_card::Type::TWO_HEARTS);
  m_cards << new joker_card(joker_card::Type::TWO_SPADES);
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
  QRandomGenerator random
    (static_cast<quint32> (QTime(0, 0, 0).secsTo(QTime::currentTime())));

  for(int i = 0; i < m_cards.size(); i++)
    {
      auto const index = static_cast<int> (random.generate()) % m_cards.size();
      auto card_1 = m_cards[i];
      auto card_2 = m_cards[index];

      m_cards.replace(i, card_2);
      m_cards.replace(index, card_1);
    }
}
