#include <bits/stdc++.h> 
using namespace std;
int n, sum;
int num[105];
int main(){
	scanf("%d", &n);
	int now = 0;
	int step;
	for (int i = 0; i < n; ++i){
		scanf("%d", &step);
		if (now < step){
//			printf("%d < %d", now, sum);
			sum += 6*(step-now);
		}
		else if (now > step){
			sum += 4*(now-step);
		}
		now = step;
		sum += 5;
	}
	printf("%d", sum);
	return 0;
}
