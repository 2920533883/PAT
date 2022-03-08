#include <bits/stdc++.h>
using namespace std;
struct p{
	string name;
	string time;
	string status;
} record[1005];
int pr[24];
int n;
bool cmp(const struct p a, const struct p b){
	return a.time < b.time;
}
bool v[1005];
int main(){
	for (int i = 0; i < 24; ++i) scanf("%d", &pr[i]);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		cin >> record[i].name >> record[i].time >> record[i].status;
	}
	sort(record, record+n, cmp);
	for (int i = 0; i < n; ++i){
		
	}
	return 0;
}
