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

#ifndef _joker_card_h_
#define _joker_card_h_

class joker_card
{
 public:
  enum Type
  {
    ACE_CLUBS = 0,
    ACE_DIAMONDS,
    ACE_HEARTS,
    ACE_SPADES,
    EIGHT_CLUBS,
    EIGHT_DIAMONDS,
    EIGHT_HEARTS,
    EIGHT_SPADES,
    FIVE_CLUBS,
    FIVE_DIAMONDS,
    FIVE_HEARTS,
    FIVE_SPADES,
    FOUR_CLUBS,
    FOUR_DIAMONDS,
    FOUR_HEARTS,
    FOUR_SPADES,
    JACK_CLUBS,
    JACK_DIAMONDS,
    JACK_HEARTS,
    JACK_SPADES,
    JOKER_1,
    JOKER_2,
    KING_CLUBS,
    KING_DIAMONDS,
    KING_HEARTS,
    KING_SPADES,
    NINE_CLUBS,
    NINE_DIAMONDS,
    NINE_HEARTS,
    NINE_SPADES,
    QUEEN_CLUBS,
    QUEEN_DIAMONDS,
    QUEEN_HEARTS,
    QUEEN_SPADES,
    SEVEN_CLUBS,
    SEVEN_DIAMONDS,
    SEVEN_HEARTS,
    SEVEN_SPADES,
    SIX_CLUBS,
    SIX_DIAMONDS,
    SIX_HEARTS,
    SIX_SPADES,
    TEN_CLUBS,
    TEN_DIAMONDS,
    TEN_HEARTS,
    TEN_SPADES,
    THREE_CLUBS,
    THREE_DIAMONDS,
    THREE_HEARTS,
    THREE_SPADES,
    TWO_CLUBS,
    TWO_DIAMONDS,
    TWO_HEARTS,
    TWO_SPADES
  };

  joker_card(const Type type);
  ~joker_card();

 private:
  Type m_type;
};

#endif
