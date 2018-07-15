#ifndef _TEST_SETUP_H
#define _TEST_SETUP_H

#include <stdlib.h>
#include <stdio.h>

#include "dominion.h"

struct gameState * testSetup()
{
  struct gameState * g = newGame();
  int * testCards = kingdomCards(
    (int)adventurer,
    (int)smithy,
    (int)council_room,
    (int)remodel,
    (int)village,
    (int)mine,
    (int)minion,
    (int)village,
    (int)embargo,
    (int)ambassador
    );
  initializeGame(3, testCards, 12345678, g);

  return g;
}

void printState(struct gameState * g)
{
  printf("<<GAME STATE!>>\n");
  printf("Total players: %d\n", g->numPlayers);
  printf("Whose turn: %d\n", g->whoseTurn);
  printf("Hand: \n");
  for (int i = 0; i < g->handCount[g->whoseTurn]; i++)
  {
    printf("> %d\n", g->hand[ g->whoseTurn ][ i ]);
  }
  printf("<<END GAME STATE!>>\n");
}

#endif
