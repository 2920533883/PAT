#include <bits/stdc++.h>
using namespace std;
int coupons[100005];
int product[100005];
bool cmp(int a, int b){
	if (a > 0 || b > 0) return a > b;
	else return a < b;
}
int n, m;
long long ans;

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &coupons[i]);
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) scanf("%d", &product[i]);
	sort(coupons, coupons+n, cmp);
	sort(product, product+m, cmp);
	int ns = 0;
	while (product[ns] > 0) ns++;
	int flag1 = 0, flag2 = ns;
	for (int i = 0; i < n; ++i){
		if (coupons[i] < 0){
			if (flag2 < m)
			ans += (coupons[i]*product[flag2++]);
		}
		if (coupons[i] > 0){
			if (flag1 < ns)
			ans += (coupons[i]*product[flag1++]);
		}
	}
	printf("%lld", ans);
	return 0;
}
