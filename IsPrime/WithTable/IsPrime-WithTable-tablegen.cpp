//#include<stdio.h>
#include<bitset>
#define NUMMAX 2147483648

void calc(void){  
	FILE* fp;
	long cnt,JMAX;
	fopen_s(&fp,"primes.dat","wb");
	std::bitset<NUMMAX/2+1> num;
	JMAX=(NUMMAX+1)>>1;
	num.set();
	long two=2;
	fwrite(&two,sizeof(long),1,fp);
	//cnt=1;
	for(long long i=3;i<=NUMMAX;i+=2){
		if(num[i>>1]){
			//cnt++;
			fwrite(&i,sizeof(long),1,fp);
			for(long j=i>>1;j<JMAX;j+=i){
				num.reset(j);
			}
		}
	}

	fclose(fp);
	/*
	fopen_s(&fp,"count.dat","wb");
	fwrite(&cnt,sizeof(long),1,fp);
	fclose(fp);
	*/
}

int main(void){
	calc();
	return 0;
}
