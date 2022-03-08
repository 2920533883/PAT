#include <bits/stdc++.h>
using namespace std;
string num;
int a[10005];
int main() {
	cin >> num;
	string res = "";
	int indexD = num.find(".");
	int indexE = num.find("E");
	int len = 0;
	for (int i = 1; i < indexE; ++i){
		if (isdigit(num[i])) a[len++] = num[i]-'0';
	}
	int index = atoi(num.substr(indexE+2).c_str());
	if (num[0] == '+'){
		if (num[indexE+1] == '+'){
			if (indexE-indexD > index){
				for (int i = 0; i < len; ++i) {
					if (i == indexD+index-1) res += '.';
					res += a[i]+'0';
				}
			}
			else {
				for (int i = 0; i < len; ++i) {
					res += a[i]+'0';
				}
				for (int i = 0; i < index-(indexE-indexD)+1; ++i) res += '0';
			}	
		}
		else {
			if (indexD-1 > index){
				cout << index << endl;
				for (int i = 0; i < len; ++i) {
					if (i == indexD-index-1) res += '.';
					res += a[i]+'0';
				}
			}
			else {
				res += "0.";
				for (int i = 0; i < index-indexD+1; ++i) res += '0';
				for (int i = 0; i < len; ++i) {
					res += a[i]+'0';
				}
			}
		}
	}
	else {
		res += "-";
		if (num[indexE+1] == '+'){
			if (indexE-indexD > index){
				for (int i = 0; i < len; ++i) {
					if (i == indexD+index-1) res += '.';
					res += a[i]+'0';
				}
			}
			else {
				for (int i = 0; i < len; ++i) {
					res += a[i]+'0';
				}
				for (int i = 0; i < index-(indexE-indexD)+1; ++i) res += '0';
			}	
		}
		else {
			if (indexD-1 > index){
				cout << index << endl;
				for (int i = 0; i < len; ++i) {
					if (i == indexD-index-1) res += '.';
					res += a[i]+'0';
				}
			}
			else {
				res += "0.";
				for (int i = 0; i < index-indexD+1; ++i) res += '0';
				for (int i = 0; i < len; ++i) {
					res += a[i]+'0';
				}
			}
		}
	}
	cout << res << endl;
	return 0;
}
