#include <bits/stdc++.h>
#define MAXN 26 * 26 * 26 * 10 + 1
using namespace std;
map<string, int> nameToIndex;
priority_queue<int, vector<int>, greater<int> > rate[MAXN];
/*
	注意数据范围，所有学生的数量是 26 * 26 * 26 * 10，而不是40000，40000是查询人数 
	而却优先队列比set快，set会超时 
*/
int n, k, ct;
void add(string name, int r){
	int index = nameToIndex[name];
	if (!index){
		nameToIndex[name] = ++ct;
		rate[ct].push(r);
	}
	else {
		rate[index].push(r);
	}
	
}
int main(){
	scanf("%d %d", &n, &k);
	int a, b;
	string name;
	while (k--){
		scanf("%d %d", &a, &b);
		while (b--){
			cin >> name;
			add(name, a);
		}
	}
	while (n--){
		cin >> name;
		int index = nameToIndex[name];
		cout << name;
		if (!rate[index].empty()){
			
			printf(" %d", rate[index].size());
			while(!rate[index].empty()){
				cout << " " << rate[index].top();
				rate[index].pop();
			}
		}
		else printf(" 0");
		printf("\n");
		
	}
	return 0;
} 
