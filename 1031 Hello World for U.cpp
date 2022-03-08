#include <bits/stdc++.h>
using namespace std;
string n;
int main() {
	cin >> n;
	int n1 = 0, n2 = 0, len = n.size();
	for (int i = 3; i <= len; ++i){
		for (int j = 1; j <= i; ++j){
			if (i+2*j == len+2){
				n1 = max(n1, j);

			}
		}
	}
	n2 = len+2-2*n1;
//	printf("%d %d\n", n1, n2);
	for (int i = 0; i < n1-1; ++i){
		cout << n[i];
		for (int j = 0; j < n2-2; ++j) printf(" ");
		cout << n[len-1-i] << endl;
	}
	for (int i = n1-1; i < n1-1+n2; ++i) cout<< n[i];
	return 0;
}
