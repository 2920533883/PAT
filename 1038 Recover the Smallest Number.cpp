#include <bits/stdc++.h>
using namespace std;
string num[10005];
int n;
string ans;
/*
按照组合小的排序  a+b < b+a
*/
bool cmp(const string a, const string b) {
	return a+b < b+a;
}
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) cin >> num[i];
	sort(num, num+n, cmp);
	for (int i = 0; i < n; ++i) ans += num[i];
	int i = 0;
	while (ans[i] == '0') i++;
	// 全是0要输出0 
	if (i == ans.size()) cout << "0";
	else 
	for (; i < ans.size(); ++i){
		cout << ans[i];
	}
	return 0;
}
