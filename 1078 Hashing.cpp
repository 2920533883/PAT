#include <bits/stdc++.h>
using namespace std;
/*
	二次方探测法
	如果hashTable里面key % size的下标对应的hashTable为false,说明这个下标没有被使用过，直接输出。
	否则step步长从1加到m-1，求得index = (key + step * step) % size，如果v[index]为false,说明找到了。 
	如果都没有找到就输出"-"
*/ 
int prime[10000005];
int size;
bool v[10000005];
int n, m;
void quickPrime(int upperBound){
	for (int i = 2; i <= upperBound; ++i){
		if (!v[i]) {
			prime[size++] = i;
			v[i] = true;
		}
		for (int j = 0; j < size && prime[j]*i <= upperBound; ++j){
			v[i*prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}

void insert(int key){
	for (int i = 0; i < m; ++i){
		int index = (i*i + key)%m;
		if (!v[index]){
			printf("%d", index%m);
			v[index] = true;
			return ;
		}
	}
	printf("-");
}
int main(){
	scanf("%d %d", &m, &n);
	int num;
	quickPrime(m*2);
	m = prime[lower_bound(prime, prime+size, m)-prime];
	memset(v, 0, sizeof(v));
	for (int i = 0; i < n; ++i){
		if (i != 0) printf(" ");
		scanf("%d", &num);
		insert(num);
	}
	return 0;
}
