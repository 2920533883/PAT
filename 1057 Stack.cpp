#include <bits/stdc++.h>
using namespace std;
/*
	直接模拟会超时
	需要动态维护一个中间值
	multiset 可以重复存值，其他与set一致 
*/
int mid = 0; //中值
multiset<int> upper;  //大于中位数的从小到大排序
multiset<int,greater<int>>lower; //小于中位数的从大到小排序

void adjust(int *mid){ //调整中位数
    if(upper.size() > lower.size()){
        lower.insert(*upper.begin());
        upper.erase(upper.begin());
    }
    else if(lower.size() > upper.size()+1){
        upper.insert(*lower.begin());
        lower.erase(lower.begin());
    }
    *mid = *lower.begin();
}

int main(){
    stack<int> st1;
    int n;
    scanf("%d",&n);
    char op[11];
    int stem;
    for(int i = 0; i < n; i++){
        scanf("%s",op);
        if((op[1] == 'o' && st1.size() == 0) || (op[1] == 'e' && st1.size() == 0)){  //非法情况
            printf("Invalid\n");
            continue;
        }
        else if(op[1] == 'u'){  //push操作
            scanf("%d",&stem);
            st1.push(stem);
            if (stem > mid) upper.insert(stem);
            else lower.insert(stem);
            adjust(&mid);
        }
        else if(op[1] == 'o'){  //pop操作
            int key = st1.top();
            printf("%d\n",st1.top());
            st1.pop();
            if (key > *lower.begin()) upper.erase(upper.find(key));
            else lower.erase(lower.find(key));
            if (st1.empty()) mid = 0;
            else adjust(&mid);
        }
        else if(op[1] == 'e'){ 
            printf("%d\n",mid);
        }
    }
    return 0;
}


