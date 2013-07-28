#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<vector>
#include <string>
int main(){
  using namespace std;

	char* hw1="Hello";
	char hw2[16]="World!";
	cout<<hw1<<" "<<hw2<<endl;

	vector<char> hw3(16);
	strcpy((char*)&hw3[0],"Hello");
	string hw4("World!");
	cout<<&hw3[0]<<" "<<hw4<<endl;

	return 0;
}
