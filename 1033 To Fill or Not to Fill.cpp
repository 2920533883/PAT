#include <bits/stdc++.h>
using namespace std;
struct node{
	double p;
	int dis;
} gas[100005];
int C, D, A, N;
bool cmp(const struct node a, const struct node b){
	if (a.dis != b.dis) return a.dis < b.dis;
	return a.p < b.p;
}
double ans;
int main(){
	scanf("%d %d %d %d", &C, &D, &A, &N);
	for (int i = 0; i < N; ++i){
		scanf("%lf %d", &gas[i].p, &gas[i].dis);
	}
	int len = C*A;
	sort(gas, gas+N, cmp);
	if (gas[0].dis != 0) {
		printf("The maximum travel distance = 0.00\n");
		return 0;
	}
	gas[N].dis = D;
	gas[N].p = 0;
	double nlen = 0;
	int nsta = 0;
	while (gas[nsta].dis <= D){
		bool flag1 = false, flag2 = false;
		for (int i = nsta+1; i <= N; ++i){
			if (gas[i].dis >= gas[nsta].dis && gas[i].dis <= gas[nsta].dis+len){
				flag1 = true;
				if (gas[i].p < gas[nsta].p){
					int cost = gas[i].dis-gas[nsta].dis;
					if (cost > nlen){
						ans += (double)(cost-nlen)*gas[nsta].p;
						nlen = 0;
					}
					else {
						nlen -= cost;
					}
					nsta = i;
					flag2 = true;
					break;
				}
			}
		}
		if (gas[nsta].dis >= D) break;
		if (!flag1) {
			printf("The maximum travel distance = %0.2lf\n", (double)gas[nsta].dis+(double)len);
			return 0;
		}
		if (!flag2){
			ans += (double)(len-nlen)*gas[nsta].p;
			nlen = len;
			int minsta = 10000;
			double minp = 1000;
			for (int i = nsta+1; i <= N; ++i){
				 if (gas[i].dis >= gas[nsta].dis && gas[i].dis <= gas[nsta].dis+len && gas[i].p < minp){
				 	minp = gas[i].p;
				 	minsta = i;
				 }
			}
			nlen -= (gas[minsta].dis-gas[nsta].dis);
			nsta = minsta;
			
		}
		
	}
	printf("%.2lf", ans/(double)A);
	return 0;
}
