#include <bits/stdc++.h>
using namespace std;
int n, m, sum;
int dis[100005], qzh[100005];
/*
	因为是圆形前缀和求路径和，然后用总路径减去前缀和的就是另一条路的路径和，输出较小的那个。 
*/
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i){
		scanf("%d", &dis[i]);
		sum += dis[i];
	}
	
	for (int i = 1; i <= n; ++i) qzh[i] = qzh[i-1]+dis[i];
	scanf("%d", &m);
	int s, e;
	while (m--){
		scanf("%d %d", &s, &e);
		int res = qzh[max(s-1, e-1)] - qzh[min(s-1, e-1)];
		printf("%d\n", min(res, sum-res));
	}
	return 0;
}
