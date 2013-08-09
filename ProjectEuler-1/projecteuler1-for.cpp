//this program will take about 3/1000000 seconds
#include <stdio.h>
#define MAX 1000
int main(){
	register int mod3=3,mod5=5;
	int sum=0;
	//for(int j=0;j<1000000;j++){
	for(int i=1;i<MAX;i++){
		register int flag=0;
		mod3--;mod5--;
		if(!mod3){mod3=3;flag=1;}
		if(!mod5){mod5=5;flag=1;}
		if(flag){sum+=i;}
	}
	//}
	printf("The sum of all the multiples of 3 or 5 below MAX is %d.\n",sum);
	return 0;
}
