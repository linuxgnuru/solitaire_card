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
#ifndef __CARDS_H
#define __CARDS_H

#include <vector>
using namespace std;

enum suits { diamond, club, heart, spade, ERR };
enum { ACE = 1, TEN = 10, JACK = 11, QUEEN = 12, KING = 13 };

/*
struct suits {
  int diamond = 1;
	int club = 2;
	int heart = 3;
	int spade = 4;
};
*/

class Card
{
private:
	unsigned int rank;
	suits suit;
	static const unsigned int rank_max = 13;

public:
	Card();
	~Card();
	
	unsigned int GetRank() const;
	suits GetSuit() const;
	void SetRank(unsigned int rv);
	void SetSuit(suits sv);
};

#endif
