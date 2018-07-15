#include "dominion.h"
#include "dominion_helpers.h"

#include "cardEffect.h"

int ce_adventurer(struct gameState * state)
{
  int currentPlayer = whoseTurn(state);
  int drawntreasure = 0;
  int temphand[MAX_HAND];
  int cardDrawn;
  int z = 0; // Temp hand counter
  
  while(drawntreasure<2)
  {
    //if the deck is empty we need to shuffle discard and add to deck
    if (state->deckCount[currentPlayer] <1){
        shuffle(currentPlayer, state);
    }
    drawCard(currentPlayer, state);
    //top card of hand is most recently drawn card.
    cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];
    if (cardDrawn = copper || cardDrawn == silver || cardDrawn == gold)
    {
      drawntreasure++;
    }
    else
    {
      temphand[z]=cardDrawn;
      //this should just remove the top card (the most recently drawn one).
      state->handCount[currentPlayer]--; 
      z++;
    }
  }
  while(z-1>=0)
  {
    // discard all cards in play that have been drawn
    state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1];
    z=z-1;
  }
  return 0;
}


int ce_smithy(struct gameState * state)
{
  int currentPlayer = whoseTurn(state);
  for (int i = 0; i < 3; i++)
  {
    drawCard(currentPlayer, state);
  }

  return 0;
}

int ce_council_room(struct gameState * state, int handPos)
{
  int currentPlayer = whoseTurn(state);
  //+4 Cards
  for (int i = 0; i < 4; i++)
  {
    drawCard(currentPlayer, state);
  }			
  //+1 Buy
  state->numBuys++;
			
  //Each other player draws a card
  for (int i = 0; i < state->numPlayers; i++)
  {
    if ( i == currentPlayer )
    {
      drawCard(i, state);
    }
  }
  //put played card in played card pile
  discardCard(handPos, currentPlayer, state, 0);

  return 0;
}

int ce_remodel(struct gameState * state, int handPos, int choice1, int choice2)
{
  int currentPlayer = whoseTurn(state);

  int j = state->hand[currentPlayer][choice1];  //store card we will trash

  if ( (getCost(state->hand[currentPlayer][choice1]) + 2) > getCost(choice2) )
  {
    return -1;
  }

  gainCard(choice2, state, 0, currentPlayer);

  //discard card from hand
  discardCard(handPos, currentPlayer, state, 0);

  //discard trashed card
  for (int i = 0; i < state->handCount[currentPlayer]; i++)
  {
    if (state->hand[currentPlayer][i] == j)
    {
      discardCard(i, currentPlayer, state, 0);			
      break;
    }
  }
  return 0;
}

int ce_village(struct gameState * state, int handPos)
{
  int currentPlayer = whoseTurn(state);
  //+2 Actions
  state->numActions = state->numActions + 2;
  //discard played card from hand
  discardCard(handPos, currentPlayer, state, 0);
  return 0;

}

