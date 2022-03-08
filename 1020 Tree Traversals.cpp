#include <bits/stdc++.h>
using namespace std;
/*
根据中序和后序，求出层序遍历 
先建树，再bfs求层序遍历 
*/
struct node{
	int data;
	int l, r;
} t[35];
int n;
int post[35], in[35];
// l1 - r1 后序左子树   l2 - r2 中序左子树 
int create(int l1, int r1, int l2, int r2){
	if (l1 > r1 || l2 > r2) return 0;
	int root = post[r1];
	int k = l2;
	while (in[k] != root) k++;
	t[root].data = root;
	t[root].l = create(l1, l1+k-1-l2, l2, k-1);
	t[root].r = create(l1+k-l2, r1-1, k+1, r2);
	return root;
}

void bfs(int root){
	queue<int> q;
	q.push(root);
	while (!q.empty()){
		int now = q.front();
		q.pop();
		if (t[now].l != 0) q.push(t[now].l);
		if (t[now].r != 0) q.push(t[now].r);
		if (q.empty())printf("%d", now);
		else printf("%d ", now);
	}
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i){
		scanf("%d", &post[i]);
	}
	for (int i = 1; i <= n; ++i){
		scanf("%d", &in[i]);
	}
	int root = create(1, n, 1, n);
	bfs(root);
	return 0;
}
