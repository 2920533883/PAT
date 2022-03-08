#include <bits/stdc++.h>
using namespace std;
typedef struct node{
	int id;
	int ge, gi;
	int rank;
	vector<int> preferredSchools;
} Student;
Student s[40005];
int n, m, k;
int quota[105];
vector<int> school[105];
int last[105];
bool cmp(const Student &a, const Student &b){
	if (a.ge+a.gi!= b.ge+b.gi) return a.ge+a.gi > b.ge+b.gi;
	else return a.ge > b.ge;
}
int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; ++i) scanf("%d", &quota[i]);
	int preferredSchool;
	for (int i = 0; i < n; ++i){
		scanf("%d %d", &s[i].ge, &s[i].gi);
		s[i].id = i;
		for (int j = 0; j < k; ++j){
			scanf("%d", &preferredSchool);
			s[i].preferredSchools.push_back(preferredSchool);
		}
	}
	sort(s, s+n, cmp);
	for (int i = 0; i < n; ++i){
		if (i > 0 && s[i].ge == s[i-1].ge && s[i].ge+s[i].gi == s[i-1].ge+s[i-1].gi) s[i].rank = s[i-1].rank;
		else s[i].rank = i+1;
	}
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < s[i].preferredSchools.size(); ++j){
			preferredSchool = s[i].preferredSchools[j];
			if (quota[preferredSchool] > 0 || s[last[preferredSchool]].rank == s[i].rank){
				school[preferredSchool].push_back(s[i].id);
				quota[preferredSchool]--;
				last[preferredSchool] = i; // 注意这里记录的是i，不能是id
				break;
			}
		}
	}
	for (int i = 0; i < m; ++i){
		sort(school[i].begin(), school[i].end());
		if (school[i].size() > 0)
		for (int j = 0; j < school[i].size(); ++j){
			if (j != 0) printf(" ");
			printf("%d", school[i][j]);
		}
		printf("\n");
	}
	return 0;
}
