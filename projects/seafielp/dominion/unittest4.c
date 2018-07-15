#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"

#include "testSetup.h"

void testFullDeckCount()
{
  struct gameState * g = testSetup();

  if (DEBUG) {
    printState(g);
  }
  
  // At the start of a game, the player should have 7 copper.
  if (fullDeckCount(0, copper, g) == 7)
    printf("numHandcards: PASS player 1 has 7 copper\n");
  else
    printf("numHandcards: FAIL player 1 has 7 copper\n");

  if (fullDeckCount(1, copper, g) == 7)
    printf("numHandcards: PASS player 2 has 7 copper\n");
  else
    printf("numHandcards: FAIL player 2 has 7 copper\n");

  if (fullDeckCount(2, copper, g) == 7)
    printf("numHandcards: PASS player 3 has 7 copper\n");
  else
    printf("numHandcards: FAIL player 3 has 7 copper\n");
}


int main(int argc, char * argv[])
{
  testFullDeckCount();
  return 0;
}
