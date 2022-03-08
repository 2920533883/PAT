#include <bits/stdc++.h>
using namespace std;
/*
	cin cout 超时，需要string、char 互转，通过scanf  printf 输入输出 
*/
int n, k;
string sname;
vector<string> v[2505];
int main(){
	scanf("%d %d", &n, &k);
	int c, course_num;
	char name[4];
	while (n--){
		scanf("%s", &name);
		scanf("%d", &c);
		sname = name;
		while (c--){
			scanf("%d", &course_num);
			v[course_num].push_back(sname);
		}
	}
	for (int i = 1; i <= k; ++i){
		printf("%d %d\n", i, v[i].size());
		sort(v[i].begin(), v[i].end());
		for (int j = 0; j < v[i].size(); ++j) printf("%s\n", v[i][j].c_str());
	}
	return 0;
} 
