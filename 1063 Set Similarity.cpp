#include <bits/stdc++.h>
using namespace std;
int n, m, num, k;
vector<int> v[55];
int in[55];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i){
		scanf("%d", &m);
		while (m--){
			scanf("%d", &num);
			v[i].push_back(num);
		}
	}
	scanf("%d", &k);
	int a, b;
	while (k--){
		int nc = 0;
		scanf("%d %d", &a, &b);
		if (!in[a]) {
			sort(v[a].begin(), v[a].end());
			in[a] = unique(v[a].begin(), v[a].end())-v[a].begin();
		}
		if (!in[b]) {
			sort(v[b].begin(), v[b].end());
			in[b] = unique(v[b].begin(), v[b].end())-v[b].begin();
		}
		for (int i = 0; i < in[a]; ++i){
			for (int j = 0; j < in[b]; ++j){
				if (v[a][i] == v[b][j]) nc++;
			}
		}
		int i = 0, j = 0;
		while (i < in[a] && j < in[b]){
			if (v[a][i] <= v[b][j]) {
				v[54].push_back(v[a][i]);
				i++;
			}
			else {
				v[54].push_back(v[b][j]);
				j++;
			}
		}
		while (i < in[a]) {
			v[54].push_back(v[a][i]);
			i++;
		}
		while (j < in[b]){
			v[54].push_back(v[b][j]);
			j++;
		}
		int nt = unique(v[54].begin(), v[54].end())-v[54].begin();
		printf("%.1lf%%\n", (double)nc*100.0/(double)nt);
		v[54].clear();
	}
	return 0;
}
