#include <bits/stdc++.h>
using namespace std;
int n, m, num;
vector<long long> num1;
set<long long> num2;
int main(){
	scanf("%d %d", &n, &m);
	while (m--){
		for (int i = 0; i < n; ++i){
			scanf("%d", &num);
			num1.push_back(num);
			num2.insert(num);
		}
	}
	set<long long> :: iterator i;
	long long maxi = 0, maxc = 0;
	for (i = num2.begin(); i != num2.end(); ++i){
		if (count(num1.begin(), num1.end(), *i) > maxc){
			maxc = count(num1.begin(), num1.end(), *i);
			maxi = *i;
		}
	}
	printf("%lld\n", maxi);
	return 0;
}
