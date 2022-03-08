#include <bits/stdc++.h>
using namespace std;
string num = "0123456789ABC";

string re(string a){
	string res = "";
	for(int i = a.size()-1; i >= 0; --i){
		res+=a[i];
	}
	return res;
}
string to13(int a){
	string res = "";
	while (a){
		res += (num[a%13]);
		a /= 13;
	}
	return re(res);
}


int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	string sa = to13(a);
	string sb = to13(b);
	string sc = to13(c);
	if (sa.size() == 0) sa = "00";
	else if (sa.size() == 1) sa = "0"+sa;
	if (sb.size() == 0) sb = "00";
	else if (sb.size() == 1) sb = "0"+sb;
	if (sc.size() == 0) sc = "00";
	else if (sc.size() == 1) sc = "0"+sc;
	string res = sa+sb+sc;
	printf("#");
	cout << res;
	return 0;
}
