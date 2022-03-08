#include <bits/stdc++.h>
using namespace std;
typedef struct node {
	string name, gender, subject;
	int grade;
} Stu;
bool cmp(const Stu a, const Stu b){
	if (a.gender != b.gender) return a.gender < b.gender;
	return a.grade > b.grade;
}
Stu stu[1005];
int n;
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		cin >> stu[i].name >> stu[i].gender >> stu[i].subject >> stu[i].grade;
	}
	sort(stu, stu+n, cmp);
	if (stu[0].gender != stu[n-1].gender){
		cout << stu[0].name << " " << stu[0].subject << endl;
		cout << stu[n-1].name << " " << stu[n-1].subject << endl;
		cout << stu[0].grade-stu[n-1].grade << endl;
	}
	else {
		if (stu[0].gender == "M"){
			cout << "Absent" << endl;
			cout << stu[n-1].name << " " << stu[n-1].subject << endl;
			cout << "NA" << endl;
		}
		if (stu[0].gender == "F"){
			cout << stu[0].name << " " << stu[0].subject << endl;
			cout << "Absent" << endl;
			cout << "NA" << endl;
		}
	}
	return 0;
}
