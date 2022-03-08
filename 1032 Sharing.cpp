#include <bits/stdc++.h>
using namespace std;
struct node{
	string data;
	int ne;
} li[100005];
/*
00060 00060 3
00060 i 00002
00003 g -1
00002 n 00003
*/
int s1, s2;
int n;
int path1[100005], path2[100005];
int main(){
	
	scanf("%d %d %d", &s1, &s2, &n);
	int add;
	for (int i = 0; i < n; ++i){
		scanf("%d", &add);
		cin >> li[add].data >> li[add].ne;
	} 
	int now = s1;
	int size1 = 0, size2 = 0;
	while (now != -1){
		path1[size1++] = now;
		now = li[now].ne;
	}
	now = s2;
	while (now != -1){
		path2[size2++] = now;
		now = li[now].ne;
	}
	int i = size1-1;
	int j = size2-1;
	while (path1[i] == path2[j] && i >= 0 && j >= 0) i--, j--;
	if (i == size1-1) printf("-1");
	else printf("%05d", path1[i+1]);
	return 0;
} 
