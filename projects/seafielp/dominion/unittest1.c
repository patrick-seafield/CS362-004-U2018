#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"


void testCompare()
{
  int ninety = 90;
  int zero = 0;
  int negativeTen = -10;
  
  if (compare(&ninety, &zero) == 1)
    printf("compare: PASS greater than\n");
  else
    printf("compare: FAIL greater than\n");

  if (compare(&negativeTen, &zero) == -1)
    printf("compare: PASS less than\n");
  else
    printf("compare: FAIL less than\n");
 
  if (compare(&zero, &zero) == 1)
    printf("compare: PASS equal to\n");
  else
    printf("compare: FAIL equal to\n");
    
}


int main(int argc, char * argv[])
{
  testCompare();
  return 0;
}
