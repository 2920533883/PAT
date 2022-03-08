#include <bits/stdc++.h> 
using namespace std;
int res[10000005];
int size;
/*
	因为数据问题，所以不能用字符串来存转换之后的数字，改用数组
*/
void toR(int num, int base){
	while (num){
		res[size++] = num%base;
		num /= base;
	}
	return ;
}
int num, base;
int main(){
	scanf("%d %d", &num, &base);
	toR(num, base);
	int l = 0, r = size-1;
	bool flag = true;
	while (l <= r){
		if (res[l] != res[r]){
			flag = false;
		}
		l++;
		r--;
	}
	if (flag) printf("Yes\n");
	else printf("No\n");
	for (int i = size-1; i >= 0 ; --i){
		cout << res[i];
		if (i != 0) cout << " ";
	}
	return 0;
}
