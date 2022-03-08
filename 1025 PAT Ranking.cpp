#include<bits/stdc++.h>
using namespace std;
/*
分组排序问题，需要注意排名相同时，要按ID递减的方式排序。
先排序计算他们的排名
再排序来正确输出
*/
typedef struct ${
	string id;
	int score;
	int fr;
	int lr;
	int ln;
} S;
S stu[30005];
int n, k;
bool cmp(const S a, const S b){
	if (a.fr != b.fr) return a.fr < b.fr;
	else if (a.score != b.score) return a.score > b.score;
	return a.id < b.id;
}
int main() {
	scanf("%d", &n);
	int count = 1;
	for (int i = 1; i <= n; ++i){
		scanf("%d", &k);
		while (k--){
			cin >> stu[count].id >> stu[count].score;
			stu[count].ln = i;
			count++;
		}
	}
	sort(stu+1, stu+count, cmp);
	int score[105], rank[105], temp[105];
	memset(score, -1, sizeof(score));
	fill(temp, temp+n+1, 1);
	for (int i = 1; i < count; ++i){
		int ln = stu[i].ln;
		if (score[ln] != stu[i].score){
			score[ln] = stu[i].score;
			rank[ln] = temp[ln];	
		}
		stu[i].lr = rank[ln];
		temp[ln]++; 
	}
	stu[1].fr = 1;
	for (int i = 2; i < count; ++i){
		if (stu[i].score == stu[i-1].score){
			stu[i].fr = stu[i-1].fr;
		}
		else {
			stu[i].fr = i;
		}
	}
	sort(stu+1, stu+count, cmp);
	printf("%d\n", count-1);
	for (int i = 1; i < count; ++i){
		cout << stu[i].id;
		printf(" %d %d %d\n", stu[i].fr, stu[i].ln, stu[i].lr);
	}
	return 0;
}
