#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "cardEffect.h"
#include "testSetup.h"

void testSmithyCardEffect()
{
  struct gameState * g = testSetup();

  if (DEBUG) {
    printState(g);
  }
  
  ce_smithy(g);

  // Smithy has you draw three cards, so the hand size should be 8.
  if (g->handCount[0] == 8)
    printf("smithy: PASS hand has 5+3 cards\n");
  else
    printf("smithy: FAIL hand has 5+3 cards\n");
}


int main(int argc, char * argv[])
{
  testSmithyCardEffect();
  return 0;
}
