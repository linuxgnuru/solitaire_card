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
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

#include "cards.h"
#include "random.h"

Card::Card()
{
}

Card::~Card()
{
}

unsigned int Card::GetRank() const
{
  return rank;
}

suits Card::GetSuit() const
{
	return suit;
}

void Card::SetRank(unsigned int rv)
{
	assert((rv > 0) && (rv <= rank_max));
	rank = rv;
}

void Card::SetSuit(suits sv)
{
	suit = sv;
}
