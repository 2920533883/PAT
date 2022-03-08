#include <bits/stdc++.h>
using namespace std;
/*
二叉搜索树:左子树的值均小于根节点,右子树的值均大于等于根节点 
*/ 
int pre[10005];
int post[10005];
int n, size;
bool flag;
void bst(int l, int r){
	if (l > r) return ;
	int root = pre[l];
	int h = l+1; // 右子树起始 
	int t = r; // 左子树尾 
	if(!flag){
		while (pre[h] < root && h <= r) h++; // 找 第一个>=根的位置作为右子树的起始 
		while (pre[t] >= root && t > l) t--; // 找 最后一个<根的位置作为左子树的尾 
	}
	else{
		while (pre[h] >= root && h <= r) h++; 
		while (pre[t] < root && t > l) t--;
	}
	if(h - t != 1) return ;
	bst(l+1, t);
	bst(h, r);
	post[++size] = root;
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &pre[i]);
	bst(1, n);
	if (size == n){
		printf("YES\n");
		for (int i = 1; i <= size; ++i){
			if (i == 1) printf("%d", post[i]);
			else printf(" %d", post[i]);
		}
	}
	else {
		memset(post, 0, sizeof(post));
		flag = true;
		size = 0;
		bst(1, n);
		if (size == n){
			printf("YES\n");
			for (int i = 1; i <= size; ++i){
				if (i == 1) printf("%d", post[i]);
				else printf(" %d", post[i]);
			}
		}
		else printf("NO\n");
	}
	return 0;
} 
