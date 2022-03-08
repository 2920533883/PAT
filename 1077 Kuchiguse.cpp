#include <bits/stdc++.h> 
using namespace std;
string sentence[100005];
int n, minSize = 100000000;
string ans;
int main(){
	scanf("%d\n", &n);
	for (int i = 0; i < n; ++i) {
		getline(cin, sentence[i]);
		minSize = min(minSize, (int)sentence[i].size());
	}
	int offset = 0;
	bool flag = false;
	while (1){
		bool flag2 = true;
		for (int i = 1; i < n; ++i){
			if (sentence[0][sentence[0].size()-1-offset] != sentence[i][sentence[i].size()-1-offset]){
				flag2 = false;
				break;
			}
		}
		if (flag2){
			flag = true;
			ans += sentence[0][sentence[0].size()-1-offset];
		}
		else break;
		offset++;
		if (offset >= minSize) break;
	}
	reverse(ans.begin(), ans.end());
	if (flag) cout << ans << endl;
	else printf("nai\n");
	return 0;
}
