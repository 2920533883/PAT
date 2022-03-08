#include <bits/stdc++.h>
using namespace std;

int f[1005];
int mapp[1005][1005];

int find(int x){
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}
void uni(int x, int y){
	f[find(x)] = find(y);
}
int n, m, k;
int main(){
	scanf("%d %d %d", &n, &m, &k);
	
	int from, to;
	for (int i = 0; i < m; ++i){
		scanf("%d %d", &from, &to);
		mapp[from][to] = 1;
		mapp[to][from] = 1;
	}
	int down;
	for (int i = 0; i < k; ++i){
		scanf("%d", &down);
		for (int i = 1; i <= n; ++i) f[i] = i;
		for (int j = 1; j <= n; ++j){
			if (j != down){
				for (int k = j+1; k <= n; ++k){
					if (k != down){
						if (mapp[j][k]) uni(j, k);
					}
				}
			}
		}
		set<int> s;
		for (int j = 1; j <= n; ++j) s.insert(find(j));
		printf("%d\n", s.size()-2);
	}
	return 0;
}
