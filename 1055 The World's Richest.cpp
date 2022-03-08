#include <bits/stdc++.h>
using namespace std;
typedef struct node{
	string name;
	int age;
	int worth;
} P;
P p[100005];
bool cmp(P a, P b){
	if (a.worth != b.worth) return a.worth > b.worth;
	if (a.age != b.age) return a.age < b.age;
	if (a.name != b.name) return a.name < b.name;
}
int n, m;
int main(){
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i){
		cin >> p[i].name >> p[i].age >> p[i].worth;
	}
	sort(p, p+n, cmp);
	int cnt, s, e;
	for (int i = 1; i <= m; ++i){
		bool flag = false;
		scanf("%d %d %d", &cnt, &s, &e);
		printf("Case #%d:\n", i);
		for (int j = 0; j < n; ++j){
			if (p[j].age >= s && p[j].age <= e) {
				cout << p[j].name;
				printf(" %d %d\n", p[j].age, p[j].worth);
				cnt--;
				flag = true;
			}
			if (cnt <= 0) break;
		}
		if (!flag) printf("None\n");
	}
	return 0;
}
