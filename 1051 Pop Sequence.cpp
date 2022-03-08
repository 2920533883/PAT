#include <bits/stdc++.h>
using namespace std;
int m, n, k;
int num[1005];
int main(){
	scanf("%d %d %d", &m, &n, &k);
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < n; ++j){
			scanf("%d", &num[j]);
		}
		int now = 1;
		int index = 0;
		stack<int> s;
		bool flag = true;
		while (now <= n){
			if (num[index] == now){
				index++;
				now++;
			}
			else {
				if (s.empty()) {
					s.push(now);
					now++;
				}
				else {
					if (num[index] == s.top()){
						while (num[index] == s.top()){
							index++;
							s.pop();
							if (s.empty() || index >= n) break;
						}
					}
					else {
						if (s.size() < m-1) {
							s.push(now);
							now++;	
						}
						else {
							flag = false;
							break;	
						}
					}
				}
			}
		}
		if (!s.empty()){
			while(num[index] == s.top()){
				s.pop();
				index++;
				if (s.empty()) break;
			}
		}
		
		
		if (flag && s.size() == 0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
