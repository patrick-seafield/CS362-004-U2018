#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"

#include "testSetup.h"

void testNumHandCards()
{
  struct gameState * g = testSetup();

  if (DEBUG) {
    printState(g);
  }
  
  // At the start of a game, the player should have 5 cards.
  if (numHandCards(g) == 5)
    printf("numHandcards: PASS hand has 5 cards\n");
  else
    printf("numHandCards: FAIL hand has 5 cards\n");
}


int main(int argc, char * argv[])
{
  testNumHandCards();
  return 0;
}
