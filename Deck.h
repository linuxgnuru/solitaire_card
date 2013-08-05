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
// Deck.h
#ifndef __DECK_H
#define __DECK_H

#include <iostream>
#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <sys/types.h>
//#include <sys/time.h>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

#define TRUE 1
#define FALSE 0

#include "cards.h"

class Deck
{
private:
  
	enum { HEARTS = 1, SPADES, DIAMONDS, CLUBS, ERR };
	enum { ACE = 1, TEN = 10, JACK = 11, QUEEN = 12, KING = 13 };
	enum { DECK_SZ = 52 };
	
	struct player
	{
		char name[30];
		int pid;
		vector<Card> hand;
		int pos;
	};
	Card *newdeck;
	vector<Card> cards;
	
	player p;
	
	int use_newdeck;
	int num_newdeck;
	int left_over;
	int is_shuffled;

	void MakeDeck();
	void Error(char *emsg);
	void PrintCard(Card my_card);
	bool isEmpty() const;
	
public:
	
	int ErrNum;
	Deck();
	~Deck(void);
	void Shuffle();
	void ShowDeck();
	int DeckLeft();
	void Draw(Card &c);
	void printCard(Card c);
		
};

#endif
