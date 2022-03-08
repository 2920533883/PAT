#include <bits/stdc++.h>
using namespace std;
/*
	ֱ��ģ��ᳬʱ
	��Ҫ��̬ά��һ���м�ֵ
	multiset �����ظ���ֵ��������setһ�� 
*/
int mid = 0; //��ֵ
multiset<int> upper;  //������λ���Ĵ�С��������
multiset<int,greater<int>>lower; //С����λ���ĴӴ�С����

void adjust(int *mid){ //������λ��
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
        if((op[1] == 'o' && st1.size() == 0) || (op[1] == 'e' && st1.size() == 0)){  //�Ƿ����
            printf("Invalid\n");
            continue;
        }
        else if(op[1] == 'u'){  //push����
            scanf("%d",&stem);
            st1.push(stem);
            if (stem > mid) upper.insert(stem);
            else lower.insert(stem);
            adjust(&mid);
        }
        else if(op[1] == 'o'){  //pop����
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


