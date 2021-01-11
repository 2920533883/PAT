#include <bits/stdc++.h> 
#define MAX 1000000
using namespace std;
int mapp[505][505];
int n, m, s, e;
int weight[505];
int dist[505];
int path_count[505];
int max_weight[505];
bool v[505];
void dijkstra(){
	fill(dist, dist+n, MAX);
	max_weight[s] = weight[s];
	dist[s] = 0;
	path_count[s] = 1;
	for (int i = 0; i < n; ++i){
		int minn = MAX, next = 0;
		for (int j = 0; j < n; ++j){
			if (dist[j] < minn && !v[j]){
				minn = dist[j];
				next = j;
			}
		}
		if (minn < MAX){
			v[next] = true;
			for (int j = 0; j < n; ++j){
				if (mapp[next][j] < MAX){
					if (dist[j] == dist[next] + mapp[next][j]) {
						path_count[j] += path_count[next];
						max_weight[j] = max(max_weight[j], max_weight[next]+weight[j]);
					}
					else if (dist[j] > dist[next] + mapp[next][j]){
						dist[j] = dist[next] + mapp[next][j];
						max_weight[j] = max_weight[next]+weight[j];
						path_count[j] = path_count[next];
					}
				}
			} 
		}
	}
}

int main(){
	scanf("%d %d %d %d", &n, &m, &s, &e);
	for (int i = 0; i < n; ++i){
		fill(mapp[i], mapp[i]+n, MAX);
	}
	for (int i = 0; i < n; ++i){
		scanf("%d", &weight[i]);
	}
	int x, y, z;
	for (int i = 0; i < m; ++i){
		scanf("%d %d %d", &x, &y, &z);
		mapp[x][y] = z;
		mapp[y][x] = z;
	}
	dijkstra();
	printf("%d %d", path_count[e], max_weight[e]);
	return 0;
}
