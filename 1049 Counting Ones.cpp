#include<bits/stdc++.h>
using namespace std;
/*
	��ǰ����λ index, λ��Ϊ now, ��λhigh, ��λlow 
	index = 0,height*now 
	index = 1,height*now + low + 1
	index > 1,(height+1) * now
*/ 
int getOne(int n){
	int now = 1, index, height, low, sum=0;
	while(n/now != 0){
		index = (n/now) % 10;
		height = n / (now*10);
		low = n - (n/now)*now;
		if (index == 0) sum += height * now;
		else if (index == 1) sum += height*now + low + 1;
		else if (index > 1) sum += (height+1) * now;
		now *= 10;
	}
	return sum;
}
int main(){
	int n;
	scanf("%d", &n);
	printf("%d\n", getOne(n));
	return 0;
}
