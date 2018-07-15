#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "cardEffect.h"
#include "testSetup.h"

void testAdventurerCardEffect()
{
  struct gameState * g = testSetup();

  if (DEBUG) {
    printState(g);
  }
  
  ce_adventurer(g);

  // Adventurer has you draw two more gold, so the hand size should be 7.
  if (g->handCount[0] == 7)
    printf("adventurer: PASS hand has 5+2 cards\n");
  else
    printf("adventurer: FAIL hand has 5+2 cards\n");

  
  // If we take the effect of the adventurer, at the start of the game,
  // indexes 5 and 6 should be copper (treasure).
  if (g->hand[0][5] == copper && g->hand[0][5] == copper)
    printf("adventurer: PASS hand contains two more copper\n");
  else
    printf("adventurer: FAIL hand contains two more copper\n");
}


int main(int argc, char * argv[])
{
  testAdventurerCardEffect();
  return 0;
}
