#include <bits/stdc++.h>
using namespace std;
typedef struct node{
	int w, index;
	vector<struct node> child;
} Node;
Node node[105];
int ans[10005];
int n, m, s;
bool cmp(Node a, Node b){
	return a.w > b.w;
}
void dfs(int now, int weight, int step){
	if (weight == 0 && node[now].child.size() == 0){
		printf("%d", node[0].w);
		for (int i = 0; i < step; ++i) printf(" %d", ans[i]);
		printf("\n");
		return ;
	}
	else if (weight < 0) return ;
	else {
		vector<struct node> childList = node[now].child;
		sort(childList.begin(), childList.end(), cmp);
		for (int i = 0; i < childList.size(); ++i){
			ans[step] = childList[i].w;
			dfs(childList[i].index, weight-childList[i].w, step+1);
		}
	}
	return ;
}
int main(){
	scanf("%d %d %d", &n, &m, &s);
	for (int i = 0; i < n; ++i){
		scanf("%d", &node[i].w);
		node[i].index = i;
	}
	int index, cnt, child;
	for (int i = 0; i < m; ++i){
		scanf("%d %d", &index, &cnt);
		while (cnt--){
			scanf("%d", &child);
			node[index].child.push_back(node[child]);
		}
	}
	dfs(0, s-node[0].w, 0);
	return 0;
}
