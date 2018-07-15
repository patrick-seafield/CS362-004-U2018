#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"

#include "testSetup.h"

void testWhoseTurn()
{
  struct gameState * g = testSetup();

  if (DEBUG) {
    printState(g);
  }
  
  // At the start of a game, the player should have 5 cards.
  if (whoseTurn(g) == g->whoseTurn)
    printf("whoseTurn: PASS correct player\n");
  else
    printf("whoseTurn: FAIL correct player\n");

}


int main(int argc, char * argv[])
{
  testWhoseTurn();
  return 0;
}
