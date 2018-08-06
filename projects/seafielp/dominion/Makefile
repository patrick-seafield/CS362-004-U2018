CFLAGS = -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o cardEffect.o
	gcc -c dominion.c -g  $(CFLAGS)

cardEffect.o: cardEffect.h cardEffect.c
	gcc -c cardEffect.c -g $(CFLAGS)

playdom: dominion.o playdom.c cardEffect.o
	gcc -o playdom playdom.c -g dominion.o rngs.o cardEffect.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o cardEffect.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o cardEffect.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o cardEffect.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o cardEffect.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o cardEffect.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o cardEffect.o $(CFLAGS)

testAll: dominion.o testSuite.c cardEffect.o
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o cardEffect.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

randomtestadventurer: rngs.o dominion.o cardEffect.o
	gcc -o randomtestadventurer -g randomtestadventurer.c rngs.o dominion.o cardEffect.o $(CFLAGS)

randomtestcard1: rngs.o dominion.o cardEffect.o
	gcc -o randomtestcard1 -g randomtestcard1.c rngs.o dominion.o cardEffect.o $(CFLAGS)

randomtestcard2: rngs.o dominion.o cardEffect.o
	gcc -o randomtestcard2 -g randomtestcard2.c rngs.o dominion.o cardEffect.o $(CFLAGS)


runtests: testDrawCard randomtestadventurer randomtestcard1 randomtestcard2
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

	./randomtestadventurer 2>&1 > randomtestadventurer.out
	gcov randomtestadventurer.c >> randomtestadventurer.out
	cat randomtestadventurer.c.gcov >> randomtestadventurer.out

	./randomtestcard1 2>&1 > randomtestcard1.out
	gcov randomtestcard1.c >> randomtestcard1.out
	cat randomtestcard1.c.gcov >> randomtestcard1.out

	./randomtestcard2 2>&1 > randomtestcard2.out
	gcov randomtestcard2.c >> randomtestcard2.out
	cat randomtestcard2.c.gcov >> randomtestcard2.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o cardEffect.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe randomtestadventurer randomtestcard1 randomtestcard2
