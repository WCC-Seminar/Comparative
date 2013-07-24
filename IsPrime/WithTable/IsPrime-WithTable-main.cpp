#include<stdio.h>
#include "IsPrime-WithTable-head.h"

int main(){
	Cprime* Prime=new Cprime(50);
	printf("3番目の素数は%luです。\n",Prime->GetPrime(3));
	printf("7が素数なら1: %d\n",Prime->IsPrime(7));
	printf("6が素数なら1: %d\n",Prime->IsPrime(6));
	printf("10までに素数は%lu個です。\n",Prime->CountPrimes(10));
	return 0;
}
