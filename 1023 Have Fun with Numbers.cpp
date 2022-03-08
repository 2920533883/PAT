#include <bits/stdc++.h>
using namespace std;
/*
	简单的一道大数乘法，将一开始的数的出现次数记录
	再将做完运算的数与记录的次数进行消除，最后从0-9都为0就是正确的！ 
*/
int nums[10];
int cheng[25];
string num;
int size = 24;
void cal(){
	
	for (int i = num.size()-1; i >= 0; --i) {
		int a = (num[i]-'0')*2;
		cheng[size] += (a%10);
		cheng[--size] += a/10;
	}
	while (cheng[size] == 0) size++;
	for (int i = size; i <= 24; ++i) {
		nums[cheng[i]]--;
	}
}
int main() {

	cin >> num;
	for (int i = 0; i < num.size(); ++i) {
		nums[num[i]-'0']++; 
	}
	cal();
	for (int i = 0; i <= 9; ++i){
		if (nums[i] != 0) {
			printf("No");
			for (int i = size; i <= 24; ++i) printf("%d", cheng[i]);
			return 0;
		}
	}
	printf("Yes\n");
	for (int i = size; i <= 24; ++i) printf("%d", cheng[i]);
	return 0;
}
