#include <bits/stdc++.h>
using namespace std;
int n, m;
int coins[100005];
int num[100005];
int main(){
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &coins[i]);
		num[coins[i]]++;
	}
	sort(coins, coins+n);
	for (int i = 0; i < n; ++i){
		num[coins[i]]--;
		if (num[m-coins[i]]){
			printf("%d %d", coins[i], m-coins[i]);
			return 0;
		}
	}
	printf("No Solution\n");
	return 0;
}
