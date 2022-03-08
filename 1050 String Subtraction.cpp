#include <bits/stdc++.h>
using namespace std;
string s1, s2, ans;
int main(){
	
	getline(cin, s1);
	getline(cin, s2);
	
	for (int i = 0; i < s1.size(); ++i){
		if (s1[i] == ' ' || s2.find(s1[i]) == s2.npos){
			ans += s1[i];
		}
	}
	int size = ans.size()-1;
	while (ans[size] == ' ') size--;
	ans.resize(size+1);
	cout << ans;
	return 0;
}
