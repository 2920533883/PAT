#include <bits/stdc++.h>
using namespace std;
int p[100000], size;
bool v[100005];
void prime(){
	memset(v, true, sizeof(v));
	v[0] = v[1] = false;
	for (int i = 2; i < 100000; ++i){
		if (v[i])p[size++] = i;
		for (int j = 0; j < size && p[j]*i < 100000; ++j){
			v[p[j]*i] = false;
			if (i%p[j] == 0) break;
		}
	}
}

string reverse(string a){
	string b;
	for (int i = a.size()-1; i >= 0; --i) b += a[i];
	return b;
}
// 10 convert to others and reverse
string convert1(int num, int radix){
	string res;
	while (num >= radix){
		int ys = num%radix;
		int shang = num /= radix;
		res += ys+'0';
	}
	res += num+'0';
	return res;
}
// others convert to 10
int convert2(string num, int radix){
	int ans = 0;
	for (int i = num.size()-1; i >= 0; --i){	
		ans += pow(radix, num.size()-i-1)*(num[i]-'0');
	}
	return ans;
}
int main(){
	prime();
	int num, radix;
	scanf("%d", &num);
	while (num > 0){
		scanf("%d", &radix);
		if (radix == 10){
			if (v[num]){
				int re = atoi(reverse(to_string(num)).c_str());
				if (v[re]){
					printf("Yes\n");
				}
				else {
					printf("No\n");
				} 
			}
			else printf("No\n");
		}
		else {
			if (v[num]){
				int re = convert2(convert1(num, radix), radix);
				if (v[re]){
					printf("Yes\n");
				}
				else {
					printf("No\n");
				} 
			}
			else {
				printf("No\n");
			}
		}
		scanf("%d", &num);
	}
	return 0;
}
