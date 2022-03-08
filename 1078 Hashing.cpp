#include <bits/stdc++.h>
using namespace std;
/*
	���η�̽�ⷨ
	���hashTable����key % size���±��Ӧ��hashTableΪfalse,˵������±�û�б�ʹ�ù���ֱ�������
	����step������1�ӵ�m-1�����index = (key + step * step) % size�����v[index]Ϊfalse,˵���ҵ��ˡ� 
	�����û���ҵ������"-"
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
