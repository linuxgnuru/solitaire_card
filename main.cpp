/*
 *
 * main.cpp
 *
 * Main function for C++ class testing.
 *
 * John Wiggins
 * 08/14/2000
 * 09/17/2002 - re-opened / mucked around
 * 28/02/2006 - converted email class to Card
 *
 */

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
#include <string.h>
#include "Deck.h"
#include "cards.h"

int main(int argc, char **argv)
{
  Deck *ptrDeck;
	int i, j, k, go, q;
	Card c;
	Card m[52];
	int zzz = FALSE;
	int dflag = FALSE;
	int noflag = FALSE;
	int runtimes = 1;
	int last_n = 0;

	srand(time(NULL));
	//dealnum = (argc == 2 ? atoi(argv[1]) : 26);
	if (argc >= 2)
	{
		if (strcmp(argv[1], "num") == 0)
		{
			noflag = TRUE;
		}
		else if (strcmp(argv[1], "deck") == 0)
		{
			zzz = TRUE;
		}
		else if ((strcmp(argv[1], "run") == 0) && (argc == 3))
		{
			noflag = TRUE;
			runtimes = atoi(argv[2]);
		}
	}
	for (go = 0; go < runtimes; go++)
	{
		//if (runtimes != 1) cout << "Run: " << go << endl;
		//zzz = (argc >= 2 ? TRUE : FALSE);
		ptrDeck = new Deck();
		//cout << "--=={ before shuffle }==--\n";
		//ptrDeck->ShowDeck();
		// Shuffle a few times to make sure its shuffled.
		for (k = 0; k < 4; k++)
			ptrDeck->Shuffle();
		//cout << "--=={ after shuffle }==--\n";
		//ptrDeck->ShowDeck();
		if (zzz == TRUE)
			ptrDeck->ShowDeck();
		dflag = FALSE;
		last_n = 0;
		for (i = 0; i < 52; i++)
		{
			ptrDeck->Draw(c);
			m[last_n] = c;
			if (last_n >= 3)
			{
				do
				{
					if (last_n >= 3)
					{
						if (m[last_n-3].GetRank() == m[last_n].GetRank())
						{
							dflag = TRUE;
							if (noflag == FALSE)
							{
								cout << "[" << (last_n < 10 ? "0" : "") << last_n << "] ";
								for (k = 0; k <= last_n-4; k++)
								{
									ptrDeck->printCard(m[k]);
									cout << " ";
								}
								cout << "[";
								for (k = last_n-3; k <= last_n; k++)
								{
									if (k == last_n)
										cout << "(";
									ptrDeck->printCard(m[k]);
									if (k != last_n)
										cout << " ";
									else
										cout << ")";
								}
								cout << "]\n";
							}
							last_n -= 4;
						}
//#pragma mark SAME SUIT
						else if (m[last_n-3].GetSuit() == m[last_n].GetSuit())
						{
							if (noflag == FALSE)
							{
								cout << "["  << (last_n < 10 ? "0" : "") << last_n << "] ";
								for (k = 0; k <= last_n; k++)
								{
									if (k == last_n - 2) cout << "[";
									if (k == last_n) cout << "(";
									ptrDeck->printCard(m[k]);
									if (k == last_n) cout << ")";
									if (k == last_n - 1) cout << "]";
									cout << " ";
								}
								cout << endl;
							}
							m[last_n - 2] = m[last_n];
							last_n -= 2;
							dflag = TRUE;
						}
						else
							dflag = FALSE;
					}
					else
						dflag = FALSE;
					//cout << "enter some number and then the enter key to continue.\n";
					//			cin >> zzz;
				} while (dflag == TRUE);
			}
			if (noflag == FALSE)
			{
				if (last_n > 0)
				{
					cout << "["  << (last_n < 10 ? "0" : "") << last_n << "] ";
					for (q = 0; q <= last_n; q++)
					{
						ptrDeck->printCard(m[q]);
						cout << " ";
					}
					cout << endl;
				}
			}
			last_n++;
		}
		if (noflag == TRUE)
		{
			cout << last_n << endl;
		}
		else
		{
			cout << "\nNumber of cards left: " << last_n << endl;
			if (last_n != 0)
			{
				cout << "Cards left:\n";
				for (i = 0; i < last_n; i++)
				{
					ptrDeck->printCard(m[i]);
					cout << " ";
//			if (i % 4 == 0 && i != 0)
//				cout << endl;
				}
				cout << endl;
			}
		}
		delete ptrDeck;
		//delete m;
	} // end for loop

	return 1;
}
