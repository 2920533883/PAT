#include <bits/stdc++.h>
using namespace std;
typedef struct node{
	int node, val, cost;
	bool operator < (const struct node &a) const{
		if (val != a.val) return val > a.val;
		return cost > a.cost;
	}
} N;
struct E{
	int from, to, val, cost ,next;
} e[500005];
int head[505], dist[505], co[505], path[505];
int n, m, s, d, tot;
bool v[505];
void add(int from, int to, int val, int cost){
	tot++;
	e[tot].from = from;
	e[tot].val = val;
	e[tot].to = to;
	e[tot].cost = cost;
	e[tot].next = head[from];
	head[from] = tot;
}

void dijkstra(){
	priority_queue<N> q;
	q.push((N){s, 0, 0});
	fill(dist, dist+n, 1000000);
	fill(co, co+n, 1000000);
	dist[s] = 0;
	co[s] = 0;
	while (!q.empty()){
		int now = q.top().node;
		q.pop();
		v[now] = true;
		for (int i = head[now]; i != -1; i = e[i].next){
			int to = e[i].to;
			if (dist[to] == dist[now] + e[i].val){
				if (co[to] > co[now] + e[i].cost){
					co[to] = co[now] + e[i].cost;
					path[to] = now;
					if (!v[to]) q.push((N){to, dist[to], co[to]});
				}
			}
			else if (dist[to] > dist[now] + e[i].val){
				dist[to] = dist[now] + e[i].val;
				path[to] = now;
				co[to] = co[now] + e[i].cost;
				if (!v[to]) q.push((N){to, dist[to], co[to]});
			}
		}
	}
}

int main(){
	scanf("%d %d %d %d", &n, &m, &s, &d);
	memset(head, -1, sizeof(head));
	memset(path, -1, sizeof(path));
	for (int i = 0; i < m; ++i){
		int from, to, val, cost;
		scanf("%d %d %d %d", &from, &to, &val, &cost);
		add(from, to, val, cost);
		add(to, from, val, cost);
	}
	dijkstra();
	int path1[505];
	int size = 0;
	int now = d;
	while (now != -1){
		path1[size++] = now;
		now = path[now];
	}
	for (int i = size-1; i >= 0; --i) printf("%d ", path1[i]);
	printf("%d %d", dist[d], co[d]);
	return 0;
}
