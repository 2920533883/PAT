#include <bits/stdc++.h>
using namespace std;

/*
	大数加法 
*/
string num;
int n;

string reverse(string a){
	string ans = "";
	for (int i = a.size()-1; i >= 0; --i){
		ans += a[i];
	}
	return ans;
}
string add(string a, string b){
	int na[105];
	memset(na, 0, sizeof(na));
	int size = 104;
	for (int i = a.size()-1; i >= 0; --i, --size){
		na[size] = a[i]-'0';
	}
	size = 104;
	for (int i = b.size()-1; i >= 0; --i, --size){
		na[size] += b[i]-'0';
		na[size-1] += (na[size]/10);
		na[size] %= 10;
	}
	string ans = "";
	while (na[size] == 0 && size < 105) size++;
	for (int i = size; i < 105; ++i){
		ans += (na[i]+'0');
	}
	return ans;
}

int main() {
	cin >> num >> n;
	if (num < "10"){
		cout << num << endl << "0";
		return 0;
	}
	bool flag = false;
	int l = 0, r = num.size()-1;
	while (l < r){
		if (num[l] != num[r]) {
			flag = true;
			break;
		}
		l++, r--;
	}
	if (!flag){
		cout << num << endl << "0";
		return 0;
	}
	int i;
	for (i = 1; i <= n; ++i){
		flag = false;
		num = add(num, reverse(num));
		int l = 0, r = num.size()-1;
		while (l < r){
			if (num[l] != num[r]) {
				flag = true;
				break;
			}
			l++, r--;
		}
		if(!flag) break;
	}
	cout << num << endl;
	printf("%d", i > n ? n:i);
	return 0;
}
