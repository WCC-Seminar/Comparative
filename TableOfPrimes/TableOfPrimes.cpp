//NUM億以下の素数を出します
//コンパイル時スタックサイズを大きくしといてください
//fopen_sが定義されていないコンパイラを使う際は"fp=fopen(...);"を使ってください

#include<stdio.h>
#include<bitset>
#define NUM 20
#define NUMM 80
#define NUMMAX (100000000*NUM)

void calc(void){  
	FILE* fp[NUM];
	int P=0;int p=0;
	int cnt;
	const char* Filename[NUMM]={
		"primes_0.1G.txt","primes_0.2G.txt","primes_0.3G.txt","primes_0.4G.txt","primes_0.5G.txt",
		"primes_0.6G.txt","primes_0.7G.txt","primes_0.8G.txt","primes_0.9G.txt","primes_1.0G.txt",
		"primes_1.1G.txt","primes_1.2G.txt","primes_1.3G.txt","primes_1.4G.txt","primes_1.5G.txt",
		"primes_1.6G.txt","primes_1.7G.txt","primes_1.8G.txt","primes_1.9G.txt","primes_2.0G.txt",
		"primes_2.1G.txt","primes_2.2G.txt","primes_2.3G.txt","primes_2.4G.txt","primes_2.5G.txt",
		"primes_2.6G.txt","primes_2.7G.txt","primes_2.8G.txt","primes_2.9G.txt","primes_3.0G.txt",
		"primes_3.1G.txt","primes_3.2G.txt","primes_3.3G.txt","primes_3.4G.txt","primes_3.5G.txt",
		"primes_3.6G.txt","primes_3.7G.txt","primes_3.8G.txt","primes_3.9G.txt","primes_4.0G.txt",
		"primes_4.1G.txt","primes_4.2G.txt","primes_4.3G.txt","primes_4.4G.txt","primes_4.5G.txt",
		"primes_4.6G.txt","primes_4.7G.txt","primes_4.8G.txt","primes_4.9G.txt","primes_5.0G.txt",
		"primes_5.1G.txt","primes_5.2G.txt","primes_5.3G.txt","primes_5.4G.txt","primes_5.5G.txt",
		"primes_5.6G.txt","primes_5.7G.txt","primes_5.8G.txt","primes_5.9G.txt","primes_6.0G.txt",
		"primes_6.1G.txt","primes_6.2G.txt","primes_6.3G.txt","primes_6.4G.txt","primes_6.5G.txt",
		"primes_6.6G.txt","primes_6.7G.txt","primes_6.8G.txt","primes_6.9G.txt","primes_7.0G.txt",
		"primes_7.1G.txt","primes_7.2G.txt","primes_7.3G.txt","primes_7.4G.txt","primes_7.5G.txt",
		"primes_7.6G.txt","primes_7.7G.txt","primes_7.8G.txt","primes_7.9G.txt","primes_8.0G.txt"};
	std::bitset<NUMMAX/2+1> num;
	num.set();
  fopen_s(&fp[0],Filename[0],"w");
  //fp[0]=fopen(Filename[0],"w");
	fprintf(fp[0],"2\n");
	cnt=0;
	for(long long i=3;i<=NUMMAX;i+=2){
		P=(int)(i/100000000);
		if(P!=p){fclose(fp[p]);p=P;fopen_s(&fp[P],Filename[P],"w");/*fp[P]=fopen(Filename[P],"w");*/}
		if(num[(i-1)/2]){
			cnt++;
				if(cnt==10000){fprintf(fp[P],"%d\n",i);}
			fprintf(fp[P],"%d\n",i);
			for(long long j=i;j<=NUMMAX;j+=i<<1){
				num.reset((j-1)/2);
			}
		}
	}

	fclose(fp[NUM-1]);
}

int main(void){
	calc();
	return 0;
}
