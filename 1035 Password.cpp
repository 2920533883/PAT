#include <bits/stdc++.h>
using namespace std;
int n;
struct node{
	string user, pas;
	bool flag;
}p[1005];

string modify(string pas){
	string modi_pas = "";
	for (int i = 0; i < pas.size(); ++i){
		if (pas[i] == '1') modi_pas += '@';
		else if (pas[i] == '0') modi_pas += '%';
		else if (pas[i] == 'l') modi_pas += 'L';
		else if (pas[i] == 'O') modi_pas += 'o';
		else modi_pas += pas[i];
	}
	return modi_pas;
}
int times;
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		cin >> p[i].user >> p[i].pas;
		string new_pas = modify(p[i].pas);
		if (new_pas != p[i].pas) {
			times++;
			p[i].flag = true;
			p[i].pas = new_pas;	
		}
	}
	if (times == 0) {
		if (n == 1) printf("There is 1 account and no account is modified\n");
		else printf("There are %d accounts and no account is modified\n", n);
	}
	else {
		printf("%d\n", times);
		for (int i = 0; i < n; ++i){
			if (p[i].flag){
				cout << p[i].user << " " << p[i].pas << endl;
			}
		}
	}
	
	return 0;
}
