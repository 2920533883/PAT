#include <bits/stdc++.h>
using namespace std;
/*
题目大意：给出四个字符串，前两个字符串确定日期和小时， 后两个字符串确定分钟； 
　　　　　日期：前两个字符串第一个相等的大写字母(位置相同，字母相同) A~G 分别表示星期一到星期天
　　　　　小时：在找到日期的字符串后面继续查找，找到第一个相同的数字或字母(0~9,A~N)(位置相同，字母相同),分别表示0~23
　　　　　分钟：在后面两个字符串中查找，第一个相等的字母，字母相等的位置就是分钟
*/
string s1, s2, s3, s4;
string week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
void getWeekAndHour(string a, string b){
	int flag = 0;
	string res = "";
	for (int i = 0; i < a.size(); ++i){
		for (int j = flag; j < b.size(); ++j){
			if (i == j && a[i] == b[j] && (isdigit(a[i]) || (a[i] >= 'A' && a[i] <= 'N')) && flag){
				cout << " ";
				if (a[i] >= 'A') printf("%02d", 10+a[i]-'A');
				else printf("%02d", a[i]-'0');
				return ;
			}
			if (i == j && a[i] == b[j] && a[i] >= 'A' && a[i] <= 'G'){
				flag = i+1; // 往后继续搜索 
				cout << week[a[i]-'A'];
			}
		}
	}
}
int getMinute(string a, string b){
	int i = 0;
	while (a[i] != b[i] || !isalpha(a[i])) i++;
	return i;
}
int main() {
	cin >> s1 >> s2 >> s3 >> s4;
	getWeekAndHour(s1, s2);
	cout << ":";
	printf("%02d", getMinute(s3, s4));
	return 0;
}
