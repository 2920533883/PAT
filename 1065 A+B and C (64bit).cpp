#include <bits/stdc++.h>
using namespace std;
int n;
int numa[1005], numb[1005];
/*

	高精度加减，字符串 < > 只会逐位对比，并不能真正比大小！
	substr() 字符串裁剪函数 
*/
string bigAdd(string a, string b){
	memset(numa, 0, sizeof(numa));
	memset(numb, 0, sizeof(numb));
	string res = "";
	if (a[0] == '-' && b[0] == '-' ){
		res += "-";
		for (int i = 1; i < a.size(); ++i) numa[i] = a[a.size()-i]-'0';
		for (int i = 1; i < b.size(); ++i) numb[i] = b[b.size()-i]-'0';
		int len = max(a.size(), b.size());
		for (int i = 1; i <= len; ++i){
			numa[i] += numb[i];
			numa[i+1] += (numa[i]/10);
			numa[i] %= 10;
		}
		len += 5;
		while (numa[len] == 0 && len > 1) len--;
		for (int i = len; i >= 1; --i) res += numa[i]+'0';
	}
	else if (a[0] != '-' && b[0] == '-'){
		b = b.substr(1);
		for (int i = 0; i < a.size(); ++i) numa[i+1] = a[a.size()-1-i]-'0';
		for (int i = 0; i < b.size(); ++i) numb[i+1] = b[b.size()-1-i]-'0';
		int len = max(a.size(), b.size());
		if (a < b){
			res += '-';
			for (int i = 1; i <= len; ++i){
				numb[i] -= numa[i];
				if (numb[i] < 0) {
					numb[i] += 10;
					numb[i+1]--;
				}
			}
			len += 5;
			while (numb[len] == 0 && len > 1) len--;
			for (int i = len; i >= 1; --i) res += numb[i]+'0';
		}
		else {
			for (int i = 1; i <= len; ++i){
				numa[i] -= numb[i];
				if (numa[i] < 0) {
					numa[i] += 10;
					numa[i+1]--;
				}
			}
			len += 5;
			while (numa[len] == 0 && len > 1) len--;
			for (int i = len; i >= 1; --i) res += numa[i]+'0';
		}
		
	}
	else if (a[0] == '-' && b[0] != '-'){
		a = a.substr(1);
		for (int i = 0; i < a.size(); ++i) numa[i+1] = a[a.size()-1-i]-'0';
		for (int i = 0; i < b.size(); ++i) numb[i+1] = b[b.size()-1-i]-'0';
		int len = max(a.size(), b.size());
		if (a <= b){
			for (int i = 1; i <= len; ++i){
				numb[i] -= numa[i];
				if (numb[i] < 0) {
					numb[i] += 10;
					numb[i+1]--;
				}
			}
			len += 5;
			while (numb[len] == 0 && len > 1) len--;
			for (int i = len; i >= 1; --i) res += numb[i]+'0';
		}
		else {
			res += '-';
			for (int i = 1; i <= len; ++i){
				numa[i] -= numb[i];
				if (numa[i] < 0) {
					numa[i] += 10;
					numa[i+1]--;
				}
			}
			len += 5;
			while (numa[len] == 0 && len > 1) len--;
			for (int i = len; i >= 1; --i) res += numa[i]+'0';
		}
		
	}
	else {
		for (int i = 0; i < a.size(); ++i) numa[i+1] = a[a.size()-1-i]-'0';
		for (int i = 0; i < b.size(); ++i) numb[i+1] = b[b.size()-1-i]-'0';
		int len = max(a.size(), b.size());
		for (int i = 1; i <= len; ++i){
			numa[i] += numb[i];
			numa[i+1] += (numa[i]/10);
			numa[i] %= 10;
		}
		len += 5;
		while (numa[len] == 0 && len > 1) len--;
		for (int i = len; i >= 1; --i) res += numa[i]+'0';
	}
	return res;
}

bool cmp(string a, string b){
	if (a[0] == '-' && a[0] == b[0]) {
		a = a.substr(1);
		b = b.substr(1);
		if (a.size() > b.size()) return false;
		else if (a.size() < b.size()) return true;
		else {
			for (int i = 0; i < b.size(); ++i) {
				if (a[i] > b[i]) return false;
				else if (a[i] < b[i]) return true;
			}
		}
		return false;
	}
	else if(a[0] != '-' && b[0] == '-') return true;
	else if (a[0] == '-' && b[0] != '-') return false;
	else {
		if (a.size() > b.size()) return true;
		else if (a.size() < b.size()) return false;
		else {
			for (int i = 0; i < a.size(); ++i) {
				if (a[i] > b[i]) return true;
				else if (a[i] < b[i]) return false;
			}
		}
		return false;
	}
}

int main(){
	scanf("%d", &n);
	string a, b, c;
	for (int i = 1; i <= n; ++i){
		cin >> a >> b >> c;
		string res = bigAdd(a, b);
		if (cmp(res, c)) printf("Case #%d: true\n", i);
		else printf("Case #%d: false\n", i);
	}
	return 0;
}
