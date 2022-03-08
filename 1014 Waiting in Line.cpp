#include <bits/stdc++.h>
using namespace std;
int n, m, k, qq;
int t[1005];
int ans[1005];
/*
	Point:
	Whether or not output "sorry" depends on the start time of service rather than the end time
	like the fifth client start to processes his service at 4:59, and finishes at 5:30, this record output normally
*/
int main(){
	scanf("%d %d %d %d", &n, &m, &k, &qq);
	for (int i = 1; i <= k; ++i){
		scanf("%d", &t[i]);
	}
	queue<int> q[25];
	int now[25];
	memset(now, 0, sizeof(now));
	int i = 1;
	int flag = 0;
	while(i <= k){
		for (int j = 1; j <= n; ++j){
			if (i > k || q[j].size() == m) {
				flag = 1;
				break;
			}
			if (q[j].size() < m) q[j].push(i++);	
		}
		if (flag) break;
	}
	if (i <= k){
		while (i <= k){
			int fd = 1;
			int j;
			for (j = 2; j <= n; ++j){
				if (now[fd]+t[q[fd].front()] > now[j]+t[q[j].front()]){
					fd = j;
				}
			}
			now[fd] += t[q[fd].front()];
			ans[q[fd].front()] = now[fd];
			q[fd].pop();
			q[fd].push(i++);
		}
	}
	for (int i = 1; i <= n; ++i){
		while (!q[i].empty()){
			now[i]+=t[q[i].front()];
			ans[q[i].front()] = now[i];
			q[i].pop();
		}
	}	
	int key;
	while (qq--){
		scanf("%d", &key);
		if (8+(ans[key]-t[key])/60>=17 && (ans[key]-t[key])%60 >= 0) printf("Sorry\n");
		else printf("%02d:%02d\n", 8+ans[key]/60, ans[key]%60);
	}
	return 0;
}
