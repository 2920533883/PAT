#include <bits/stdc++.h>
using namespace std;
int n, l, k;
vector<int> friends[1005];
bool v[1005];
int bfs(int index){
	memset(v, 0, sizeof(v));
	int count = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(index, 0));
	while (!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		if (v[now.first]) continue;
		else {
			// L层内的 
			if (now.second <= l) count++;
			v[now.first] = true;
			for (int i = 0; i < friends[now.first].size(); ++i){
				if (!v[friends[now.first][i]]){
					q.push(make_pair(friends[now.first][i], now.second+1));
				}
			}
		}
	}
	return count;
}
int main() {
	scanf("%d %d", &n, &l);
	int count, index;
	for (int i = 1; i <= n; ++i){
		scanf("%d", &count);
		while (count--){
			scanf("%d", &index);
			// 注意这句 
			friends[index].push_back(i);
		}
	}
	scanf("%d", &k);
	while (k--){
		scanf("%d", &index);
		printf("%d\n", bfs(index)-1); // 减去自己 
	}
	return 0;
}
