#include <bits/stdc++.h>
using namespace std;
string num[10005];
int n;
string ans;
/*
�������С������  a+b < b+a
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
	// ȫ��0Ҫ���0 
	if (i == ans.size()) cout << "0";
	else 
	for (; i < ans.size(); ++i){
		cout << ans[i];
	}
	return 0;
}
