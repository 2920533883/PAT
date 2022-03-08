#include <bits/stdc++.h>
using namespace std;
typedef struct p{
	string time;
	int pro;
} Cus;
Cus c[100005];
bool cmp(const Cus a, const Cus b){
	return a.time < b.time;
}
int n, m;
Cus win[105];
int now[105];
double wait;
int cwait(string time, int &now){
	string h, m, s;
	h = time.substr(0, 2);
	m = time.substr(3, 2);
	s = time.substr(6, 2);
	int timei = atoi(h.c_str())*60*60 + atoi(m.c_str())*60 + stoi(s.c_str());
	if (timei <= now) return now - timei;
	else {
		now = timei; 
	}
	return 0; 
}
int main(){
	scanf("%d %d", &n, &m);
    int tn = n;
	for (int i = 0; i < n; ++i){
		cin >> c[i].time >> c[i].pro;
		if (c[i].time > "17:00:00") {
			tn--;
		}
		if (c[i].pro > 60) c[i].pro = 60;
	}
	fill(now, now + m, 8*60*60);
	sort(c, c+n, cmp);
	for (int i = 0; i < m; ++i){
		wait += (cwait(c[i].time, now[i]));
		win[i] = c[i];
	}
	
	for (int i = m; i < n; ++i){	
		int index = 0;
		for (int j = 0; j < m; ++j){
			if (now[j]+win[j].pro*60 < now[index]+win[index].pro*60){
				index = j;
			}
		}
		now[index] += win[index].pro*60;
		wait += (cwait(c[i].time, now[index]));
		win[index] = c[i];
	}
	printf("%.1lf", wait/60.0/tn);
	return 0;
} 
