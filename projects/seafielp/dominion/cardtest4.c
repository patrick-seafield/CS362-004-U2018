#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "cardEffect.h"
#include "testSetup.h"

void testVillageCardEffect()
{
  struct gameState * g = testSetup();

  if (DEBUG) {
    printState(g);
  }

  g->hand[0][ g->handCount[0] ] = village;
  g->handCount[0]++;
  
  ce_village(g, g->handCount[0] - 1);

  // Village has you draw one card, so the hand size should be 6.
  if (g->handCount[0] == 6)
    printf("village: PASS hand has 5+1 cards\n");
  else
    printf("village: FAIL hand has 5+1 cards\n");

  // Village gives you two actions, so the actions should be 1-1+2 = 2
  if (g->numActions == 2)
    printf("village: PASS two actions remaining\n");
  else
    printf("village: FAIL two actions remaining\n");
}


int main(int argc, char * argv[])
{
  testVillageCardEffect();
  return 0;
}
