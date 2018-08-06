#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "dominion.h"
#include "cardEffect.h"

#include "testSetup.h"

void test_ce_adventurer()
{
  struct gameState * g = testSetup();

  ///////////////////////
  // Randomize the deck for player 0 and copy our gamestate.
  int deckSize = (rand() % MAX_DECK) + 1;
  
  for (int i = 0; i < deckSize; i++)
  {
    g->deck[0][i] = rand() % (treasure_map + 1);
  }
  g->deckCount[0] = deckSize;

  if (DEBUG)
  {
    printf("Here's the state before playing any cards.");
    printState(g);
  }

  struct gameState * og = malloc(sizeof(struct gameState));
  memcpy(og, g, sizeof(struct gameState));

  //////////////////////
  // Determine (as oracle) what should happen as the result of an Adventurer play.
  int ogTreasures[2] = {-5, -5};
  int ogTreasuresFound = 0;

  for (int i = 0; i < deckSize; i++)
  {
    if (og->deck[0][i] == copper || og->deck[0][i] == silver || og->deck[0][i] == gold)
    {
      ogTreasures[ogTreasuresFound] = og->deck[0][i];
      ogTreasuresFound++;

      if (ogTreasuresFound == 2)
      {
        break;
      }
    }
  }

  /////////////////////
  // Run ce_adventurer and compare the results.
  int initialHandSize = g->handCount[0];
  ce_adventurer(g);
  int treasuresFound = g->handCount[0] - initialHandSize;

  // The amount of treasures found should have been the same.
  if (ogTreasuresFound == treasuresFound)
    printf("ce_adventurer: PASS Found correct treasure count\n");
  else
    printf("ce_adventurer: FAIL Found correct treasure count\n");

  // The two treasures should be the last two cards put into player 0's hand.
  if (ogTreasures[0] == g->hand[0][ g->handCount[0] - 2 ]
      && ogTreasures[1] == g->hand[0][ g->handCount[0] - 1 ])
    printf("ce_adventurer: PASS Found correct treasure cards\n");
  else
    printf("ce_adventurer: FAIL Found correct treasure cards\n");

}


int main(int argc, char * argv[])
{
  srand(time(NULL));
  
  test_ce_adventurer();
  return 0;
}
