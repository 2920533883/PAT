#include <bits/stdc++.h>
using namespace std;
int num[5];
int main() {
	int n;
	scanf("%d", &n);
	while (1){
		memset(num, 0, sizeof(num));
		for(int i = 0; i < 5; ++i) {
			num[i] = n%10;
			n /= 10;
		}
		sort(num, num+5);
		int a = 0, b = 0;
		for (int i = 1; i < 5; ++i) {
			a += pow(10, 4-i)*num[i];
			b += pow(10, i-1)*num[i];
		}
		n = b - a;
		printf("%04d - %04d = %04d\n", b, a, n);
		if (n == 6174 || n == 0) break;
	}
	return 0;
}
