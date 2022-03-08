#include <bits/stdc++.h> 
using namespace std;
struct node{
	string id;
	string name;
	int score;
} p[100005];
int n, m;
bool cmp1(const struct node a, const struct node b){
	return a.id < b.id;
}
bool cmp2(const struct node a, const struct node b){
	if (a.name != b.name) return a.name < b.name;
	return a.id < b.id;
}
bool cmp3(const struct node a, const struct node b){
	if (a.score != b.score) return a.score < b.score;
	return a.id < b.id;
}
int main(){
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i){
		cin >> p[i].id >> p[i].name >> p[i].score;
	}
	switch(m){
		case 1:
			sort(p, p+n, cmp1);
			break;
		case 2:
			sort(p, p+n, cmp2);
			break;
		case 3:
			sort(p, p+n, cmp3);
			break;
	}
	for (int i = 0; i < n; ++i){
		cout << p[i].id << " " << p[i].name << " " << p[i].score << endl;
	}
	return 0;
}
