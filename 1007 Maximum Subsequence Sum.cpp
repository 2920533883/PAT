#include <bits/stdc++.h> 
using namespace std;
int n;
int num[10005];
int main(){
	scanf("%d", &n);
	int flag = 0; // 判断全负 
	for (int i = 0; i < n; ++i){
		scanf("%d", &num[i]);
		if (num[i] >= 0) flag = 1;
	}
	int head = 0, tail = n-1;
	int ans = -1, sum = 0;
	for (int i = 0; i < n; ++i){
		sum += num[i];
		// 如果当前sum < 0 sum = 0 
		if (sum < 0){
			sum = 0;
		}
		// 如果当前 sum > ans 更新ans 
		else if (sum > ans){
			ans = sum;
			tail = i;
		}
	}
	if (!flag){
		ans = 0;
		head = 0;
		tail = n-1;
	}
	else {
		// 确定起始位置 
		sum = 0;
		for (int i = tail; i >= 0; --i){
			sum += num[i];
			if (sum == ans) {
	            head = i;
	            break;
	        }
		}
	}
	printf("%d %d %d", ans, num[head], num[tail]);
	return 0;
}
