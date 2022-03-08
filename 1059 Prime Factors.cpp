#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int size;
int prime[10000005];
bool v[1000000005];
void fastPrime(){
	for (int i = 2; i <= sqrt(n); ++i){
		if (!v[i]) prime[size++] = i;
		for (int j = 0; j < size && prime[j]*i <= sqrt(n); ++j){
			v[prime[j]*i] = true;
			if (i % prime[j] == 0) break;
		}
	}
}
int main(){
	scanf("%lld", &n);
	if (n <= 1) {
		printf("%lld=%lld", n, n);
		return 0;
	}
	fastPrime();
	printf("%lld=", n);
	ll temp = n;
	int now, cnt;
	bool flag = false;
	for (int i = 0; i < size; ++i){
		now = prime[i];
		cnt = 0;
		while (temp % now == 0){
			temp /= now;
			cnt++;
			flag = true;
		}
		if (temp == 1) break;
		if (cnt == 1) printf("%d*", now);
		else if (cnt > 1) printf("%d^%d*", now, cnt);
	}
	if (cnt == 1) printf("%d", now);
	else if (cnt > 1) printf("%d^%d", now, cnt);
	if (!flag) printf("%lld", n);
	return 0;
}
