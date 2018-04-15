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
#include <errno.h>
#include <signal.h>

#include "deck.h"
#include "cards.h"
#include "colors.h"

#include <iomanip>
#include <iostream>

using namespace std;

static void die(int sig)
{
  if (sig != 0 && sig != 2) (void)fprintf(stderr, "caught signal %d\n", sig);
  if (sig == 2) (void)fprintf(stderr, "Exiting due to Ctrl + C\n");
  exit(0);
}

int main(int argc, char **argv)
{
  Deck *ptrDeck;
  Card c;
  Card m[52];
  bool showDeckFlag = FALSE;
  bool dflag = FALSE;
  bool noflag = FALSE;
  bool winflag = FALSE;
  bool alwayswinflag = FALSE;
  int runtimes = 1;
  int last_n = 0;
  int alwayswin_counter = 0;

  // note: we're assuming BSD-style reliable signals here
  (void)signal(SIGINT, die);
  (void)signal(SIGHUP, die);
  (void)signal(SIGTERM, die);
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
      showDeckFlag = TRUE;
    }
    else if ((strcmp(argv[1], "run") == 0) && (argc == 3))
    {
      noflag = TRUE;
      runtimes = atoi(argv[2]);
    }
    else if (strcmp(argv[1], "winner") == 0)
    {
      alwayswinflag = TRUE;
    }
    else
    {
      cout << "usage: " << argv[0] << " (num|deck|winner|run x)" << endl;
      return EXIT_SUCCESS;
    }
  }
  do
  {
    for (int go = 0; go < runtimes; go++)
    {
      //if (runtimes != 1) cout << "Run: " << go << endl;
      //showDeckFlag = (argc >= 2 ? TRUE : FALSE);
      ptrDeck = new Deck();
      //cout << "--=={ before shuffle }==--\n";
      //ptrDeck->ShowDeck();
      // Shuffle a few times to make sure its shuffled.
      for (int i = 0; i < 4; i++)
        ptrDeck->Shuffle();
      //cout << "--=={ after shuffle }==--\n";
      //ptrDeck->ShowDeck();
      if (showDeckFlag == TRUE)
        ptrDeck->ShowDeck();
      dflag = FALSE;
      last_n = 0;
      for (int i = 0; i < 52; i++)
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
                if (noflag == FALSE && alwayswinflag == FALSE)
                {
                  cout << "[" << (last_n < 10 ? "0" : "") << last_n << "] ";
                  for (int j = 0; j <= last_n-4; j++)
                  {
                    ptrDeck->printCard(m[j]);
                    cout << " ";
                  }
                  cout << "[";
                  for (int j = last_n-3; j <= last_n; j++)
                  {
                    if (j == last_n)
                      cout << "(";
                    ptrDeck->printCard(m[j]);
                    cout << (j != last_n ? " " : ")");
                  }
                  cout << "]\n";
                }
                last_n -= 4;
              }
              else if (m[last_n - 3].GetSuit() == m[last_n].GetSuit())
              {
                if (noflag == FALSE && alwayswinflag == FALSE)
                {
                  cout << "["  << (last_n < 10 ? "0" : "") << last_n << "] ";
                  for (int j = 0; j <= last_n; j++)
                  {
                    if (j == last_n - 2) cout << "[";
                    if (j == last_n) cout << "(";
                    ptrDeck->printCard(m[j]);
                    if (j == last_n) cout << ")";
                    if (j == last_n - 1) cout << "]";
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
          } while (dflag == TRUE);
        }
        if (noflag == FALSE && alwayswinflag == FALSE)
        {
          if (last_n > 0)
          {
            std::cout << "["  << std::setfill('0') << std::setw(2) << last_n << "] ";
            for (int i = 0; i <= last_n; i++)
            {
              ptrDeck->printCard(m[i]);
              cout << " ";
            }
            cout << endl;
          }
        }
        last_n++;
      }
      if (alwayswinflag == TRUE && last_n == 0)
      {
        winflag = TRUE;
      }
      if (noflag == TRUE && alwayswinflag == FALSE)
      {
        if (runtimes == 1)
        {
            cout << last_n << endl;
        }
        else
        {
          if (go + 1 >= runtimes || (go % 50 == 0 && go != 0))
          {
            if (go % 50 == 0 && go != 0)
              std::cout << std::setfill('0') << std::setw(2) << last_n << ',' << endl;
            else
              std::cout << std::setfill('0') << std::setw(2) << last_n << endl;
          }
          else
            std::cout << std::setfill('0') << std::setw(2) << last_n << ", ";
        }
        winflag = TRUE;
      }
      if (noflag == FALSE && alwayswinflag == FALSE)
      {
        cout << "\nNumber of cards left: " << last_n << endl;
        if (last_n != 0)
        {
          cout << "Cards left:\n";
          for (int i = 0; i < last_n; i++)
          {
            ptrDeck->printCard(m[i]);
            cout << " ";
          }
          cout << endl;
        }
        winflag = TRUE;
      }
      delete ptrDeck;
    } // end for loop
    if (alwayswinflag)
        alwayswin_counter++;
  } while (winflag == FALSE); // end do loop
  if (alwayswinflag)
  {
    cout << "Number of times before win: " << alwayswin_counter << endl;
  }
  return EXIT_SUCCESS;
}
