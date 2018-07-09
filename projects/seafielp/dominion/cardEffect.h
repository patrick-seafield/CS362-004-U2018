#ifndef _CARD_EFFECT_H
#define _CARD_EFFECT_H

#include "dominion.h"

int ce_adventurer(struct gameState * state);

int ce_smithy(struct gameState * state, int handPos);

int ce_council_room(struct gameState * state, int handPos);

int ce_remodel(struct gameState * state, int handPos, int choice1, int choice2);

int ce_village(struct gameState * state, int handPos);


#endif
