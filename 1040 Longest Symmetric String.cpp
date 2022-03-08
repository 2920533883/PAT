#include <bits/stdc++.h>
using namespace std;
string s;
int len, ans;
int main(){
	getline(cin, s);
	len = s.size();
	for (int i = 0; i < len; ++i){
		for (int j = len-1; j >= i; --j){
			bool flag = true;
			if (s[i] == s[j]){
				for (int k = 0; k <= (j-i+1)/2; ++k){
					if (s[i+k] != s[j-k]){
						flag = false;
						break;
					}
				}
				if (flag) ans = max(ans, j-i+1);
			}
		}
	}
	printf("%d", ans);
	return 0;
} 
 
