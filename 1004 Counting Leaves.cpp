#include <bits/stdc++.h>
using namespace std;
int h[10005]; // store tree height 
vector<int> v[1005]; // store tree node
int n, m;
int main(){
	scanf("%d %d", &n, &m);
	int id, num, child;
	h[1] = 1; // root node`s height is 1
	// input
	for (int i = 0; i < m; ++i){
		scanf("%d %d", &id, &num);
		while (num--){
			scanf("%d", &child);
			v[id].push_back(child);
		}
	}
	// compute every node`s height
	for (int i = 1; i <= n; ++i){
		for (int j = 0; j < v[i].size(); ++j){
			h[v[i][j]] = h[i]+1;
		}
	}
	int max_h = h[max_element(h, h+n+1)-h];
	// traverse by h
	for (int i = 1; i <= max_h; ++i){
		int ans = 0;
		for (int j = 1; j <= n; ++j){
			if (h[j] == i){
				if (!v[j].size()) ans++;
			}
		}
		if (i == 1) printf("%d", ans);
		else printf(" %d", ans);
	}
}
 
