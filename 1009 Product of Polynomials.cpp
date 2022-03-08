#include <bits/stdc++.h> 
using namespace std;
struct node{
	int a;
	double b;
} num1[1005], num2[1005];
double ans[2005];
int n, m, size;
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		scanf("%d %lf", &num1[i].a, &num1[i].b);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; ++i){
		scanf("%d %lf", &num2[i].a, &num2[i].b);
	}
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			int index = num1[i].a + num2[j].a;
			double res = num1[i].b * num2[j].b;
			ans[index] += res;
		}
	}
	for (int i = 0; i < 2005; ++i){
		if (ans[i] != 0.0) size++;
	}
	printf("%d", size);
	for (int i = 2000; i >= 0; --i){
		if(ans[i] != 0.0){
			printf(" %d %.1lf", i, ans[i]);
		}
	}
	return 0; 
}
