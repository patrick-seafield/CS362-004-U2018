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

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o cardEffect.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
	rm -f unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4

unittestresults: dominion.o cardEffect.o rngs.o unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c 
	echo "Running (seafielp) Assignment 03 unit tests for Dominion:" > unittestresults.out

	echo "Running tests for unittest1.c" >> unittestresults.out
	gcc -o unittest1 unittest1.c dominion.o cardEffect.o rngs.o $(CFLAGS)
	./unittest1 >> unittestresults.out
	gcov unittest1.c >> unittestresults.out

	echo "Running tests for unittest2.c" >> unittestresults.out
	gcc -o unittest2 unittest2.c dominion.o cardEffect.o rngs.o $(CFLAGS)
	./unittest2 >> unittestresults.out
	gcov unittest2.c >> unittestresults.out

	echo "Running tests for unittest3.c" >> unittestresults.out
	gcc -o unittest3 unittest3.c dominion.o cardEffect.o rngs.o $(CFLAGS)
	./unittest3 >> unittestresults.out
	gcov unittest3.c >> unittestresults.out

	echo "Running tests for unittest4.c" >> unittestresults.out
	gcc -o unittest4 unittest4.c dominion.o cardEffect.o rngs.o $(CFLAGS)
	./unittest4 >> unittestresults.out
	gcov unittest4.c >> unittestresults.out

	echo "Running tests for cardtest1.c" >> unittestresults.out
	gcc -o cardtest1 cardtest1.c dominion.o cardEffect.o rngs.o $(CFLAGS)
	./cardtest1 >> unittestresults.out
	gcov cardtest1.c >> unittestresults.out

	echo "Running tests for cardtest2.c" >> unittestresults.out
	gcc -o cardtest2 cardtest2.c dominion.o cardEffect.o rngs.o $(CFLAGS)
	./cardtest2 >> unittestresults.out
	gcov cardtest2.c >> unittestresults.out

	echo "Running tests for cardtest3.c" >> unittestresults.out
	gcc -o cardtest3 cardtest3.c dominion.o cardEffect.o rngs.o $(CFLAGS)
	./cardtest3 >> unittestresults.out
	gcov cardtest3.c >> unittestresults.out

	echo "Running tests for cardtest4.c" >> unittestresults.out
	gcc -o cardtest4 cardtest4.c dominion.o cardEffect.o rngs.o $(CFLAGS)
	./cardtest4 >> unittestresults.out
	gcov cardtest4.c >> unittestresults.out


