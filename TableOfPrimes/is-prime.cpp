#include<stdio.h>
#include "Cprime.h"

Cprime Prime;
int main(){
	printf("3番目の素数は%ldです。\n",Prime.GetPrime(3));
	printf("7が素数なら1: %d\n",Prime.IsPrime(7));
	printf("6が素数なら1: %d\n",Prime.IsPrime(6));
	printf("10までに素数は%ld個です。\n",Prime.CountPrimes(10));
	return 0;
}
