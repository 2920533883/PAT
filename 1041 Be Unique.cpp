#include <bits/stdc++.h>
using namespace std;
int ct[10005];
int num[100005];
int n;
int main(){
	scanf("%d", &n);
	int a;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &num[i]);
		ct[num[i]]++;
	}
	for (int i = 0; i < n; ++i){
		if (ct[num[i]] == 1) {
			printf("%d\n", num[i]);
			return 0;
		}
	}
	printf("None\n");
	return 0;
}
