#ifndef _Cprime_h
#define _Cprime_h
#define GetPrimeMax 203280221

//unsigned longå^ÇÃëfêîï\ÇéùÇ¡ÇƒÇ‹Ç∑
//unsigned long longå^Ç‹Ç≈ÇÃëfêîîªíËÇÇµÇ‹Ç∑
class Cprime{
private:
	unsigned long PrimeNum;//ì«Ç›çûÇ›ç≈ëÂêî
	unsigned long PrimeList[GetPrimeMax];
	void GetPrimeList(unsigned long Max);
	int IsPrimeDiv(unsigned long long n);
	unsigned long _CountPrimes(unsigned long n);
public:
	Cprime();
	Cprime(unsigned long Max);
	~Cprime();
	int IsPrime(unsigned long long n);
	unsigned long ListNum(void);
	unsigned long GetPrime(unsigned long n);
	unsigned long CountPrimes(unsigned long n);
	unsigned long LargestPrime(unsigned long n);
	unsigned long SmallestPrime(unsigned long n);
};

//this will load the lists of prime number.
void Cprime::GetPrimeList(unsigned long Max){
	FILE* fp;
	fopen_s(&fp,"primes.dat","rb");
	if(fp==NULL){
		//delete this;
#ifdef _INC_STDIO
		printf("Primes.dat does not exist!\n");
#else
#ifdef _IOSTREAM_
		std::cout << "Primes.dat does not exist!\n" << std::endl;
#endif
#endif
		PrimeNum=30;
		PrimeList[0]=2;  PrimeList[1]=3;  PrimeList[2]=5;  PrimeList[3]=7;  PrimeList[4]=11;
		PrimeList[5]=13; PrimeList[6]=17; PrimeList[7]=19; PrimeList[8]=23; PrimeList[9]=29;
		PrimeList[10]=31;PrimeList[11]=37;PrimeList[12]=41;PrimeList[13]=43;PrimeList[14]=47;
		PrimeList[15]=53;PrimeList[16]=59;PrimeList[17]=61;PrimeList[18]=67;PrimeList[19]=71;
		PrimeList[20]=73;PrimeList[21]=79;PrimeList[22]=83;PrimeList[23]=89;PrimeList[24]=97;
		PrimeList[25]=101;PrimeList[26]=103;PrimeList[27]=107;PrimeList[28]=109;PrimeList[29]=113;
	}else{
		fread(PrimeList,sizeof(unsigned long),Max,fp);
	}
}

//This will load the prime numbers as posible.
Cprime::Cprime(void){
	PrimeNum=GetPrimeMax;
	GetPrimeList(GetPrimeMax);
}


//This will load the prime numbers less than(?) Max.
Cprime::Cprime(unsigned long Max){
	PrimeNum=Max;
	GetPrimeList(Max);
}

//This returns the number of primes you loaded.
unsigned long Cprime::ListNum(void){
	return PrimeNum;
}

int Cprime::IsPrimeDiv(unsigned long long n){
	for(int i=0;i<PrimeNum;i++){if(!(n%PrimeList[i]))return 0;}

	if(n>PrimeList[PrimeNum-1]*PrimeList[PrimeNum-1]){
#ifdef _INC_STDIO
		printf("Too large number for your loaded prime list.\n");
#else
#ifdef _IOSTREAM_
		std::cout << "Too large number for your loaded prime list.\n" << std::endl;
#endif
#endif
		return -1;
	}else{
		return 1;
	}
}

//if n is a prime number, this returns 1.
//Otherwise, this returns 0.
int Cprime::IsPrime(unsigned long long n){
	if(n>PrimeList[PrimeNum-1]){
		return IsPrimeDiv(n);
	}else{
		unsigned long a=0;
		unsigned long b=PrimeNum-1;
		unsigned long c=b/2;
		while(a<b){
			if(PrimeList[c]==n){
				return 1;
			}else{
				if(PrimeList[c]>n){
					b=c;
				}else{
					a=c+1;
				}
				c=(unsigned long)((a+b)*0.5);
			}
		}
		if(PrimeList[c]==n)return 1;
	}
	return 0;

}



//this returns the nth prime number.
unsigned long Cprime::GetPrime(unsigned long n){
	if(n>PrimeNum){
#ifdef _INC_STDIO
        printf("Too large number for your loaded prime list.\n");
#else
#ifdef _IOSTREAM_
		std::cout << "Too large number for your loaded prime list.\n" << std::endl;
#endif
#endif
		return 0;
	}else{
		return PrimeList[n-1];
	}
}

//this will return the number of primes that are n or less than n.
unsigned long Cprime::CountPrimes(unsigned long n){  
	if(n>PrimeList[PrimeNum-1]){
#ifdef _INC_STDIO
		printf("Too large number for your loaded prime list.\n");
#else
#ifdef _IOSTREAM_
		std::cout << "Too large number for your loaded prime list.\n" << std::endl;
#endif
#endif
		return 0;
	}

	unsigned long a=0;
	unsigned long b=PrimeNum-1;
	unsigned long c=b/2;

	while(a<b){
		if(PrimeList[c]==n){
			return c;
		}else{
			if(PrimeList[c]>n){
				b=c;
			}else{
				a=c+1;
			}
			c=(unsigned long)((a+b)*0.5);
		}
	}

	return c;
}

unsigned long Cprime::LargestPrime(unsigned long n){
	if(n>PrimeList[PrimeNum-1]){
#ifdef _INC_STDIO
		printf("Too large number for your loaded prime list.\n");
#else
#ifdef _IOSTREAM_
		std::cout << "Too large number for your loaded prime list.\n" << std::endl;
#endif
#endif
		return 0;
	}else{
		return PrimeList[CountPrimes(n)];
	}
}

unsigned long Cprime::SmallestPrime(unsigned long n){
	if(n>PrimeList[PrimeNum-1]){
#ifdef _INC_STDIO
		printf("Too large number for your loaded prime list.\n");
#else
#ifdef _IOSTREAM_
		std::cout << "Too large number for your loaded prime list.\n" << std::endl;
#endif
#endif
		return 0;
	}else{
		return PrimeList[CountPrimes(n)+1];
	}
}

#endif
