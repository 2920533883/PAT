#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005], b[200005];
vector<ll> v;
int n, m;
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) scanf("%lld", &b[i]);
	int na = 0, nb = 0;
	while (na < n && nb < m){
		if (a[na] <= b[nb]){
			v.push_back(a[na]);
			na++;
		}
		else {
			v.push_back(b[nb]);
			nb++;
		}
	}
	while (na < n){
		v.push_back(a[na]);
		na++;
	}
	while (nb < m){
		v.push_back(b[nb]);
		nb++;
	}
	printf("%lld", v[(v.size()-1)/2]);
	return 0;
}
