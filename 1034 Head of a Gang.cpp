#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
const int INF = 1000000000;
map<int, string> intTostring; // ���->����
map<string, int> stringToint; // ����->���
map<string, int> Gang; // head->����
int G[maxn][maxn], weight[maxn];
int n, k, numperson = 0;
int vis[maxn]; // ��Ƿ���
void DFS(int nowvisit, int &head, int &numMember, int &totalvalue) {
	numMember++;
	vis[nowvisit] = 1;
	if (weight[nowvisit] > weight[head]) {
		head = nowvisit; // headֻ�Ǽ�¼��Ȩ���Ľ��,������Ҫ���Ǳ�Ϊ��
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
	for (int i = 0; i < numperson; i++) { // δ������ͨͼ,�����ڽӾ��� O(n^2)
		if (vis[i] == 0) {
			int head = i, numMember = 0, totalvalue = 0; // ͷĿ,��Ա��,�ܱ�Ȩ
			DFS(i, head, numMember, totalvalue); // һ��dfsһ����ͨͼ
			if (numMember > 2 && totalvalue > k) {
				Gang[intTostring[head]] = numMember; // ����ͨͼ��head
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
		intTostring[numperson] = str; // �ڼ�����
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
		int id2 = change(str2); // ��¼���ֵı��
		weight[id1] += w; // ���Ȩֵ
		weight[id2] += w;
		G[id1][id2] += w; // ��Ȩֵ��w
		G[id2][id1] += w;
	}
	// ����Ȩֵ�������
	DFSTrave();
	cout << Gang.size() << endl;
	for (auto it = Gang.begin(); it != Gang.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}
