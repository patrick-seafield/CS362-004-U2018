#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "dominion.h"
#include "cardEffect.h"

#include "testSetup.h"

void test_ce_smithy()
{
  struct gameState * g = testSetup();

  ///////////////////////
  // Set player 0's deck to contain three random cards, which we remember.
  int drawnCards[3] = { -5, -5, -5 };
  
  for (int i = 0; i < 3; i++)
  {
    drawnCards[i] = g->deck[0][i] = rand() % (treasure_map + 1);
  }
  g->deckCount[0] = 3;

  if (DEBUG)
  {
    printf("Here's the state before playing any cards.");
    printState(g);
  }


  /////////////////////
  // Run ce_smithy and compare the results.
  int handCount = g->handCount[0];
  ce_smithy(g, handCount);

  // The amount of treasures found should have been the same.
  if (g->hand[0][ handCount - 3] == drawnCards[0]
      && g->hand[0][ handCount - 2] == drawnCards[1]
      && g->hand[0][ handCount - 1] == drawnCards[2]
    )
    printf("ce_smithy: PASS Three cards drawn are the correct cards\n");
  else
    printf("ce_smithy: FAIL Three cards drawn are the correct cards\n");

}


int main(int argc, char * argv[])
{
  srand(time(NULL));
  
  test_ce_smithy();
  return 0;
}
