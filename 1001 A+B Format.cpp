#include <bits/stdc++.h>
using namespace std;
int main(){
	int a, b, flag = 0;
	cin >> a >> b;
	int ans = a+b;
	// ����ת���� 
	if(ans < 0) {
		flag = 1;
		ans *= -1;
	}
	// int ת string 
	stringstream ss;
	string s;
	ss << ans;
	s = ss.str();
	// ��� 
	if (flag) cout << "-";
	for (int i = 0; i < s.size(); ++i){
		cout << s[i];
		if ((s.size()-1-i)%3 == 0 && i != s.size()-1) cout << ",";
		
	}
	return 0;
}
