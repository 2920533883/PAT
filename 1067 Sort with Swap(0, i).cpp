#include<iostream>
using namespace std;
int n, t, ans;
int num[100005];
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
	  	cin >> t;
	  	num[t] = i;
	  } 
	  for(int i = 0; i < n; i++){  
		if(num[i] != i){ 	   
            while(num[0] != 0){
                swap(num[0], num[num[0]]);
			   	ans++;
			}	 
            if(num[i] != i){ 
            	swap(num[i], num[0]); 
                ans++;
            }
		}
	}
	cout<< ans <<endl;
}
