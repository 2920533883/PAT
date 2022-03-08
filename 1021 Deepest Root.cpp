#include <bits/stdc++.h>
using namespace std;
/*
	��ͼ�������������������Щ�ĸ��ڵ� 
	����䲻����������м�����ͨ��
	�������bfs��ÿ����Ϊ���ڵ�����ڵ㵽ÿ���ӽڵ����ȣ��ҳ��������ȣ���¼����Щ�ڵ�����ô�����ȴ������������ 
	����ͨ���ò��鼯 
*/
vector<int> mapp[10005];
int n;
bool v[10005];
int d[10005];
int f[10005];
int find(int x){
	return f[x] == x ? x : f[x] = find(f[x]);
}
void bfs(int root){
	queue<int> q;
	memset(v, false, sizeof(v));
	memset(d, 0, sizeof(d));
	q.push(root);
	v[root] = true;
	while (!q.empty()){
		int now = q.front();
		q.pop();
		for (int i = 0; i < mapp[now].size(); ++i){
			int ne = mapp[now][i];
			if (!v[ne]){
				f[find(ne)] = find(now);
				d[ne] = d[now]+1;
				q.push(ne);
				v[ne] = true;
			}
		}
	}
}

int main(){
	scanf("%d", &n);
	int from, to;
	for (int i = 0; i < n-1; ++i){
		scanf("%d %d", &from, &to);
		mapp[from].push_back(to);
		mapp[to].push_back(from);
	}
	int max = 0, index = 0;
	vector<int> ans_r;
	for (int i = 1; i <= n; ++i) f[i] = i;
	for (int i = 1; i <= n; ++i){
		bfs(i);
		index = max_element(d+1, d+1+n)-d;
		if (max < d[index]) {
			max = d[index];
			ans_r.clear();
			ans_r.push_back(i);
		}
		else if (max == d[index]){
			ans_r.push_back(i);
		}
		
	}
	
	set<int> s;
	for (int j = 1; j <= n; ++j){
		s.insert(find(f[j]));
	}
	if (s.size() != 1) {
		printf("Error: %d components", s.size());
		return 0;
	}
	for (int i = 0; i < ans_r.size(); ++i){
		printf("%d\n", ans_r[i]);
	}
	return 0;
} 
