#include <bits/stdc++.h> 
using namespace std;
double num[1005];
int main(){
	int n, size = 0;
	int a;
	float b;
	cin >> n;
	for (int i = 1; i <= n; ++i){
		cin >> a >> b;
		num[a] += b;
	}
	cin >> n;
	for (int i = 1; i <= n; ++i){
		cin >> a >> b;
		num[a] += b;
	}
    for (int i = 0; i <= 1000; ++i){
        if (num[i] != 0) size++;
    }
	printf("%d", size);
	for (int i = 1000; i >= 0; --i){
		if (num[i] != 0){
			printf(" %d %0.1f", i, num[i]);
		}
	}
	return 0;
}
