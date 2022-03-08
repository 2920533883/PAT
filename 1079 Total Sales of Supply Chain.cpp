#include<bits/stdc++.h>
using namespace std;
int n;
double r, p;
vector<pair<int, int> > supplier[100005];

double getTotalSales(){
	double res = 0.0;
	queue<pair<int, double>> q;
	q.push(make_pair(0, p));
	while (!q.empty()){
		pair<int, double> now = q.front();
		q.pop();
		for (int i = 0; i < supplier[now.first].size(); ++i){
			// 是零售商 
			if (supplier[now.first][i].second){
				q.push(make_pair(supplier[now.first][i].first, now.second*(1.0+r/100.0)));
			}
			// 是客户 
			else {
//				printf("%d %lf\n", supplier[now.first][i].first, now.second*supplier[now.first][i].first);
				res += now.second*supplier[now.first][i].first;
			}
		}
	}
	return res;
}


int main() {
	scanf("%d %lf %lf", &n, &p, &r);
	int k, index, count;
	for (int i = 0; i < n; ++i){
		scanf("%d", &k);
		if (k > 0){
			while (k--){
				scanf("%d", &index);
				supplier[i].push_back(make_pair(index, 1));
			}
		}
		else {
			scanf("%d", &count);
			supplier[i].push_back(make_pair(count, 0));
		}
	}
	printf("%.1lf", getTotalSales());
	return 0;
}
