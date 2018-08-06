#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "dominion.h"
#include "cardEffect.h"

#include "testSetup.h"

void test_ce_council_room()
{
  struct gameState * g = testSetup();

  ///////////////////////
  // Set player 0's deck to contain four random cards.
  
  for (int i = 0; i < 4; i++)
  {
    /* drawnCards[i] =  */
    g->deck[0][i] = rand() % (treasure_map + 1);
  }
  g->deckCount[0] = 4;

  // Add a random card to each other player's deck.
  for (int i = 1; i < g->numPlayers; i++)
  {
    /* otherPlayerCards[i] =  */
    g->deck[i][ g->deckCount[i] ] = rand() % (treasure_map + 1);
    g->deckCount[i]++;
  }

  if (DEBUG)
  {
    printf("Here's the state before playing any cards.");
    printState(g);
  }

  // Copy the game state so we can compare our oracle to the implementaion.
  struct gameState * og = malloc(sizeof(struct gameState));
  memcpy(og, g, sizeof(struct gameState));

  // Peform our oracle duties: player 0: +1 Buy, +4 Cards, other players: +1 Card.
  og->numBuys++;
  for (int i = 0; i < 4; i++)
  {
    og->hand[0][ og->handCount[0] ] = og->deck[0][ og->deckCount[0] - 1 ];
    og->handCount[0]++;
    og->deckCount[0]--;
  }

  for (int i = 1; i < og->numPlayers; i++)
  {
    og->hand[i][ og->handCount[i] ] = og->deck[i][ og->deckCount[i] - 1 ];
    og->handCount[i]++;
    og->deckCount[i]--;
  }


  /////////////////////
  // Run ce_ and compare the results.
  ce_council_room(g, g->handCount[0]);

  // The amount of buys has been increased properly.
  if (g->numBuys == og->numBuys)
    printf("ce_council_room: PASS Buy amount increased by 1\n");
  else
    printf("ce_council_room: FAIL Buy amount increased by 1\n");

  if (g->hand[0][ g->handCount[0] - 1] == og->hand[0][ og->handCount[0] - 1]
      && g->hand[0][ g->handCount[0] - 2] == og->hand[0][ og->handCount[0] - 2]
      && g->hand[0][ g->handCount[0] - 3] == og->hand[0][ og->handCount[0] - 3]
      && g->hand[0][ g->handCount[0] - 4] == og->hand[0][ og->handCount[0] - 4]
    )
    printf("ce_council_room: PASS Four cards drawn properly\n");
  else
    printf("ce_council_room: FAIL Four cards drawn properly\n");

  int playersDrew1 = 1;
  for (int i = 1; i < g->numPlayers; i++)
  {
    if (g->hand[i][ g->handCount[i] - 1 ] != g->hand[i][ g->handCount[i] - 1 ])
    {
      playersDrew1 = 0;
    }
  }
  
  if (playersDrew1)
    printf("ce_council_room: PASS All other players drew one card\n");
  else
    printf("ce_council_room: FAIL All other players drew one card\n");

}


int main(int argc, char * argv[])
{
  srand(time(NULL));
  
  test_ce_council_room();
  return 0;
}
