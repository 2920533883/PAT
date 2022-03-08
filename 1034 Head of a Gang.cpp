#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
const int INF = 1000000000;
map<int, string> intTostring; // 编号->人数
map<string, int> stringToint; // 姓名->编号
map<string, int> Gang; // head->人数
int G[maxn][maxn], weight[maxn];
int n, k, numperson = 0;
int vis[maxn]; // 标记访问
void DFS(int nowvisit, int &head, int &numMember, int &totalvalue) {
	numMember++;
	vis[nowvisit] = 1;
	if (weight[nowvisit] > weight[head]) {
		head = nowvisit; // head只是记录点权最大的结点,遍历主要还是边为主
	}
	for (int i = 0; i < numperson; i++) {
		if (G[nowvisit][i] > 0) {
			totalvalue += G[nowvisit][i];
			G[nowvisit][i] = G[i][nowvisit] = 0;
			if (vis[i] == 0) {
				DFS(i, head, numMember, totalvalue);
			}
		}
	}
}
void DFSTrave() {
	for (int i = 0; i < numperson; i++) { // 未必是联通图,所有邻接矩阵 O(n^2)
		if (vis[i] == 0) {
			int head = i, numMember = 0, totalvalue = 0; // 头目,成员数,总边权
			DFS(i, head, numMember, totalvalue); // 一次dfs一个联通图
			if (numMember > 2 && totalvalue > k) {
				Gang[intTostring[head]] = numMember; // 此联通图的head
			}
		}
	}
}
int change(string str) {
	if (stringToint.find(str) != stringToint.end()) {
		return stringToint[str];
	}
	else {
		stringToint[str] = numperson;
		intTostring[numperson] = str; // 第几个人
		return numperson++;
	}
}
int main() {
	int w;
	string str1, str2;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> str1 >> str2 >> w;
		int id1 = change(str1);
		int id2 = change(str2); // 记录名字的编号
		weight[id1] += w; // 结点权值
		weight[id2] += w;
		G[id1][id2] += w; // 边权值加w
		G[id2][id1] += w;
	}
	// 各边权值构造完毕
	DFSTrave();
	cout << Gang.size() << endl;
	for (auto it = Gang.begin(); it != Gang.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}
