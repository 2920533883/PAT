#include <bits/stdc++.h>
using namespace std;
struct node{
	int id;
	int score[10];
	int totalScore;
	int passCount;
	bool flag;
} user[10005];
int n, k, m;
int questionScore[10];
bool cmp(const struct node a, const struct node b){
	if (a.totalScore != b.totalScore) return a.totalScore > b.totalScore;
	if (a.passCount != b.passCount) return a.passCount > b.passCount;
	return a.id < b.id;
}
// -1没通过编译器  -2没提交过题目 
int main(){
	scanf("%d %d %d", &n, &k, &m);
	for (int i = 0; i <= n; ++i){
		for (int j = 0; j <= k; ++j) user[i].score[j] = -1;
	}
	for (int i = 1; i <= k; ++i) scanf("%d", &questionScore[i]);
	int id, question, score;
	for (int i = 0; i < m; ++i){
		scanf("%d %d %d", &id, &question, &score);
		user[id].score[question] = max(score, user[id].score[question]);
		user[id].id = id;
		if (score != -1) user[id].flag = true;
		else if (user[id].score[question] == -1){
			user[id].score[question] = -2;
		}
	}
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= k; ++j){
			if (user[i].score[j] != -1 && user[i].score[j] != -2) user[i].totalScore += user[i].score[j];
			if (user[i].score[j] == questionScore[j]) user[i].passCount++;
		}
	}
	sort(user+1, user+n+1, cmp);
	int rank = 1, nowScore = user[1].totalScore;
	for (int i = 1; i <= n; ++i){
    	if (nowScore > user[i].totalScore) {
			rank = i;
			nowScore = user[i].totalScore;
		}
		if (user[i].flag){
			printf("%d %05d %d", rank, user[i].id, user[i].totalScore);
			for (int j = 1; j <= k; ++j){
				if (user[i].score[j] == -1) printf(" -");
				else if (user[i].score[j] == -2) printf(" 0");
				else printf(" %d", user[i].score[j]);
			}
			printf("\n");
		}
	}
	return 0;
} 
