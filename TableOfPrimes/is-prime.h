#ifndef _Cprime_h
#define _Cprime_h
#define GetPrimeMax 105097565


class Cprime{
private:
  long PrimeNum;
long PrimeList[GetPrimeMax];
void GetPrimeList(long Max);
public:
Cprime();
Cprime(long Max);
int IsPrime(long n);
long GetPrime(long n);
long CountPrimes(long n);
long LargestPrime(long n);
long SmallestPrime(long n);
};

//this will load the lists of prime number.
void Cprime::GetPrimeList(long Max){
FILE* fp;
fopen_s(&fp,"primes.dat","rb");
fread(PrimeList,sizeof(long),Max,fp);

}

//This will load the prime numbers as posible.
Cprime::Cprime(void){
PrimeNum=GetPrimeMax;
GetPrimeList(GetPrimeMax);
}


//This will load the prime numbers less than(?) Max.
Cprime::Cprime(long Max){
PrimeNum=Max;
GetPrimeList(Max);
}



//if n is a prime number, this returns 1.
//Otherwise, this returns 0.
int Cprime::IsPrime(long n){
long a=0;
long b=PrimeNum-1;
long c=b>>1;
while(a<b){
if(PrimeList[c]==n){
return 1;
}else{
if(PrimeList[c]>n){
b=c;
}else{
a=c+1;
}
c=(long)((a+b)*0.5);
}
}

return 0;

}

//this returns the nth prime number.
long Cprime::GetPrime(long n){
return PrimeList[n];
}

//this will return the number of primes that are n or less than n.
long Cprime::CountPrimes(long n){  long a=0;
long b=PrimeNum-1;
long c=b*0.5;

while(a<b){
if(PrimeList[c]==n){
return c;
}else{
if(PrimeList[c]>n){
b=c;
}else{
a=c+1;
}
c=(long)((a+b)*0.5);
}
}

return c;
}

long Cprime::LargestPrime(long n){
return PrimeList[CountPrimes(n)];
}

long Cprime::SmallestPrime(long n){
return PrimeList[CountPrimes(n)+1];
}

#endif
