#include <bits/stdc++.h>
using namespace std;
struct node{
	double amount;
	double price;
} mooncake[1005];
int n;
double d;
double ans;
bool cmp(const struct node a, const struct node b){
	return a.amount/a.price < b.amount/b.price;
}
int main(){
	scanf("%d %lf", &n, &d);
	for (int i = 0; i < n; ++i) scanf("%lf", &mooncake[i].amount);
	for (int i = 0; i < n; ++i) scanf("%lf", &mooncake[i].price);
	sort(mooncake, mooncake+n, cmp);
	for (int i = 0; i < n; ++i){
		if (mooncake[i].amount <= d){
			ans += mooncake[i].price;	
			d -= mooncake[i].amount;
		}
		else {
			ans += (d*mooncake[i].price/mooncake[i].amount);
			break;
		}
	}
	printf("%.2lf\n", ans);
	return 0;
}
