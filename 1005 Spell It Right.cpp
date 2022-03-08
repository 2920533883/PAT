#include <bits/stdc++.h>
using namespace std;
string a;
string e[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int main(){
	int sum = 0;
	cin >> a;
	for (int i = 0; i < a.size(); ++i){
		sum += a[i]-'0';
	}
	stringstream ss;
	ss << sum;
	a = ss.str();
	for (int i = 0; i < a.size(); ++i){
		cout << e[a[i]-'0'];
		if (i != a.size()-1) cout << " ";	
	}
	return 0;
}
 
