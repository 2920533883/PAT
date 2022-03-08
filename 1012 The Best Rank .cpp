#include <bits/stdc++.h>
using namespace std;
typedef struct ${
	string id;
	int val;
} S;
S a[2005], c[2005], m[2005], e[2005];
/*
	Noticed students` score can be the same
	example 
		1    2    3
		99   99   99
	when you query the rank of 99, you should get 1
*/
string subs = "ACME";
int n1, n2;
bool cmp(const S x, const S y){
	return x.val > y.val;
}
int main(){
	scanf("%d %d", &n1, &n2);
	string id;
	for (int i = 0; i < n1; ++i){
		cin >> id >> c[i].val >> m[i].val >> e[i].val;
		a[i].id = id;
		c[i].id = id;
		m[i].id = id;
		e[i].id = id;
		a[i].val = (c[i].val + m[i].val + e[i].val)/3;
	}
	sort(a, a+n1, cmp);
	sort(c, c+n1, cmp);
	sort(m, m+n1, cmp);
	sort(e, e+n1, cmp);
	int index, sub;
	int flag;
	for (int i = 0; i < n2; ++i){
		index = 10000, sub = 0;
		flag = 0;
		cin >> id;	
		for (int j = 0; j < n1; ++j){
			if (a[j].id == id){
				flag = 1;
				int val = a[j].val;
				for (int k = 0; k < n1; ++k){
					if (val == a[k].val){
						j = k;
						break;
					}
				}
				if (index > j){
					sub = 0;
					index = j;
				}
				break;
			}
		}
		if (!flag){
			printf("N/A\n");
			continue; 
		}
		for (int j = 0; j < n1; ++j){
			if (c[j].id == id){
				int val = c[j].val;
				for (int k = 0; k < n1; ++k){
					if (val == c[k].val){
						j = k;
						break;
					}
				}
				if (index > j){
					sub = 1;
					index = j;
				}
				break;
			}
		}
		for (int j = 0; j < n1; ++j){
			if (m[j].id == id){
				int val = m[j].val;
				for (int k = 0; k < n1; ++k){
					if (val == m[k].val){
						j = k;
						break;
					}
				}
				if (index > j){
					sub = 2;
					index = j;
				}
				break;
			}
		}
		for (int j = 0; j < n1; ++j){
			if (e[j].id == id){
				int val = e[j].val;
				for (int k = 0; k < n1; ++k){
					if (val == e[k].val){
						j = k;
						break;
					}
				}
				if (index > j){
					sub = 3;
					index = j;
				}
				break;
			}
		}
		cout << index+1 << " " << subs[sub] << endl;
	}
	
	return 0;
}
