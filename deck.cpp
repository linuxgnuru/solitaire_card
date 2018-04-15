/*
    Copyright 2006, John Wiggins

    This file is part of bathroom_sol.

    bathroom_sol is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Foobar is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with bathroom_sol.  If not, see <http://www.gnu.org/licenses/>.

 */
// deck.cpp
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

#include "random.h"
#include "deck.h"
#include "cards.h"
#include "colors.h"

// Constructor.

// Solitare deck
Deck::Deck()
{
  MakeDeck();
  ErrNum = 1;
}

// Deconstructor.
Deck::~Deck()
{
}

// Private methods.

// Initialize deck
void Deck::MakeDeck()
{
  Card tmp_card;

  for (int j = 0; j < 4; j++)
  {
    for (int i = 1; i <= 13; i++)
    {
      tmp_card.SetRank(i);
      switch(j)
      {
        case(0):
          tmp_card.SetSuit(spade);
          cards.push_back(tmp_card);
          break;
        case(1):
          tmp_card.SetSuit(heart);
          cards.push_back(tmp_card);
          break;
        case(2):
          tmp_card.SetSuit(club);
          cards.push_back(tmp_card);
          break;
        case(3):
          tmp_card.SetSuit(diamond);
          cards.push_back(tmp_card);
          break;
      }
    }
  }
}

void Deck::Shuffle()
{
  randomInteger randfunc;
  random_shuffle (cards.begin(), cards.end(), randfunc);
  is_shuffled = TRUE;
}

// Error message.
void Deck::Error(char *emsg)
{
  fprintf(stderr, "%s\n", emsg);
}

/*void Deck::Draw()
  {
  pCard tmpc;
  if (!isEmpty())
  {
  tmpc = cards.back();
  cards.pop_back();
  }
//return tmpc;
}*/

bool Deck::isEmpty() const
{
  return (cards.size() == 0);
}

void Deck::Draw(Card &c)
{
  Card tmp;
  tmp = cards.back();
  c.SetRank(tmp.GetRank());
  c.SetSuit(tmp.GetSuit());
  cards.pop_back();
  //	PrintCard(p.hand[p.pos]);
  //	p.pos++;
  //	return retval;
}

void Deck::ShowDeck()
{
  int j = 1;
  for (int i = 0; i < DECK_SZ; i++)
  {
    PrintCard(cards[i]);
    cout << ' ';
    if (j == 13)
    {
      cout << endl;
      j = 1;
    }
    else
      j++;
  }
  cout << endl;
  //printf("\n");
}

void Deck::printCard(Card c)
{
  Card t;
  t.SetSuit(c.GetSuit());
  t.SetRank(c.GetRank());
  PrintCard(t);
}

// Prints out a single playing card
void Deck::PrintCard(Card my_card)
{
  int s = my_card.GetSuit();
  bool m = (s == heart || s == diamond ? TRUE : FALSE);
  switch (my_card.GetRank())
  {
    case(ACE): cout << (m ? RED_ : GRAY_) << 'A' << C_OFF; break;
    case(KING): cout << (m ? RED_ : GRAY_) << 'K' << C_OFF; break;
    case(QUEEN): cout << (m ? RED_ : GRAY_) << 'Q' << C_OFF; break;
    case(JACK): cout << (m ? RED_ : GRAY_) << 'J' << C_OFF; break;
    case(TEN): cout << (m ? RED_ : GRAY_) << 'T' << C_OFF; break;
    default: cout << (m ? RED_ : GRAY_) << my_card.GetRank() << C_OFF; break;

  }
  switch (my_card.GetSuit())
  {
    case(heart): cout << RED_ << S_HEART << C_OFF; break;
    case(spade): cout << GRAY_ << S_SPADE << C_OFF; break;
    case(diamond): cout << RED_ << S_DIAMOND << C_OFF;  break;
    case(club): cout << GRAY_ << S_CLUB << C_OFF;  break;
    default: fprintf(stderr, "Illegal suit: %d\n", my_card.GetSuit()); break;
  }
}

int Deck::DeckLeft()
{
  return (use_newdeck == TRUE ? num_newdeck : 0);
}
// ------------- EOF ----------------------
