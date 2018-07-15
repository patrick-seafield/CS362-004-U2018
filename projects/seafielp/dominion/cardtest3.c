#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "cardEffect.h"
#include "testSetup.h"

void testCouncilRoomCardEffect()
{
  struct gameState * g = testSetup();

  if (DEBUG) {
    printState(g);
  }

  int oldBuys = g->numBuys;

  // Just insert the card into the first player's hand.
  g->hand[0][ g->handCount[0] ] = council_room;
  g->handCount[0]++;
  ce_council_room(g, g->handCount[0] - 1);

  // Council Room has you draw four cards, so the hand size should be 9.
  if (g->handCount[0] == 9)
    printf("council room: PASS hand has 5+3 cards\n");
  else
    printf("council room: FAIL hand has 5+3 cards\n");

  // Council Room gives you an extra buy.
  if (g->numBuys == oldBuys + 1)
    printf("council room: PASS has extra buy\n");
  else
    printf("council room: FAIL has extra buy\n");
}


int main(int argc, char * argv[])
{
  testCouncilRoomCardEffect();
  return 0;
}
