#include<bitset>
#define NUMMAX 4294967294

void calc(void){	
	FILE* fp;
	unsigned long /*cnt,*/p, JMAX;
	fopen_s(&fp,"primes.dat","wb");
	std::bitset<NUMMAX/2+1> num;
	JMAX=(NUMMAX+1)/2;
	num.set();
	unsigned long two=2;
	fwrite(&two,sizeof(unsigned long),1,fp);
	//cnt=1;
	for(unsigned long long i=3;i<=NUMMAX;i+=2){
		p=i/2;
		if(num[p]){
			//cnt++;
			fwrite(&i,sizeof(unsigned long),1,fp);
			for(unsigned long long j=p;j<JMAX;j+=i){
				num.reset(j);
			}
		}
	}
/*
	fclose(fp);
	fopen_s(&fp,"count.dat","wb");
	fwrite(&cnt,sizeof(long),1,fp);
	fclose(fp);
*/
}

int main(void){
	calc();
	return 0;
}
