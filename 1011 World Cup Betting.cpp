#include <bits/stdc++.h>
using namespace std;
double p[3][3];
char e[3] = {'W','T','L'};
int main(){
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 3; ++j)
			scanf("%lf", &p[i][j]);
	}
	double ans = 1;
	for (int i = 0; i < 3; ++i){
		int index = max_element(p[i], p[i]+3)-p[i];
		ans *= p[i][index];
		printf("%c ", e[index]);
	}
	printf("%.2lf", (ans*0.65-1.0)*2.0);
	return 0;
}
 
