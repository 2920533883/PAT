#include <bits/stdc++.h>
using namespace std;
typedef struct node{
	string name;
	string sin;
	string sout;
} re;
re r[10000];
bool cmp1(const re a, const re b){
	return a.sin < b.sin;
}
bool cmp2(const re a, const re b){
	return a.sout > b.sout;
}
int n;
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		cin >> r[i].name >> r[i].sin >> r[i].sout;
	}
	sort(r, r+n, cmp1);
	string unlock = r[0].name;
	sort(r, r+n, cmp2);
	string lock = r[0].name;
	cout << unlock << " " << lock;
	return 0;
}
