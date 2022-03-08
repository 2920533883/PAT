#include <bits/stdc++.h>
using namespace std;
int g1, s1, k1, g2, s2, k2;
int main() {
	scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
	int g = g1+g2;
	int s = s1+s2;
	int k = k1+k2;
	printf("%d.%d.%d", g+(s+k/29)/17, (s+k/29)%17, k%29);
	return 0;
}
