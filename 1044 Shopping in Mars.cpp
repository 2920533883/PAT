#include <bits/stdc++.h>
using namespace std;
int dia[1000005];
long long qzh[1000005];
int n, m;
long long minn = 1000000000;
vector<pair<int, int>> ans;
int main(){
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", &dia[i]);
	qzh[1] = dia[1];
	for (int i = 2; i <= n; ++i) qzh[i] = qzh[i-1]+dia[i];
	int i = 0, j = 0;
	long long res;
	while (i <= n){
		while(qzh[j]-qzh[i] < m && j <= n){
            j++;
        }
        if(qzh[j]-qzh[i] < m){
            break;
        }
        res = qzh[j]-qzh[i]-m;
		if (res == minn){
			ans.push_back(make_pair(i+1, j));
		}
		else if (res < minn){
			ans.clear();
			minn = res;
			ans.push_back(make_pair(i+1, j));
		}
		i++;
	}
	for (int i = 0; i < ans.size(); ++i){
		cout << ans[i].first << "-" << ans[i].second << endl;
	}
	return 0;
} 
