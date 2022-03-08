#include <bits/stdc++.h>
using namespace std;
typedef struct node{
	string id;
	int v, t;

} P;
vector<P> sage, noble, fool, small; 
int n, l, h;
bool cmp(const P a, const P b){
	if (a.t+a.v != b.t+b.v) return a.t+a.v > b.t+b.v;
	else if (a.v != b.v) return a.v > b.v;
	else return a.id < b.id;
}
int main(){
	scanf("%d %d %d", &n, &l, &h);
	string id;
	int v, t;
	for (int i = 0; i < n; ++i){
		cin >> id >> v >> t;
		if (v >= h && t >= h) sage.push_back((P){id, v, t});
		else if (v >= h && t >= l && t < h) noble.push_back((P){id, v, t});
		else if (v >= l && v < h && t >= l && t < h && v >= t) fool.push_back((P){id, v, t});
		else if (v >= l && t >= l) small.push_back((P){id, v, t});
	}
	sort(sage.begin(), sage.end(), cmp);
	sort(noble.begin(), noble.end(), cmp);
	sort(fool.begin(), fool.end(), cmp);
	sort(small.begin(), small.end(), cmp);
	cout << sage.size()+noble.size()+fool.size()+small.size() << endl;
	for (int i = 0; i < sage.size(); ++i) cout << sage[i].id << " " << sage[i].v << " " << sage[i].t << endl;
	for (int i = 0; i < noble.size(); ++i) cout << noble[i].id << " " << noble[i].v << " " << noble[i].t << endl;
	for (int i = 0; i < fool.size(); ++i) cout << fool[i].id << " " << fool[i].v << " " << fool[i].t << endl;
	for (int i = 0; i < small.size(); ++i) cout << small[i].id << " " << small[i].v << " " << small[i].t << endl;
	return 0;
} 
