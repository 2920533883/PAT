#include <bits/stdc++.h>
using namespace std;
/*
��Ŀ���⣺�����ĸ��ַ�����ǰ�����ַ���ȷ�����ں�Сʱ�� �������ַ���ȷ�����ӣ� 
�������������ڣ�ǰ�����ַ�����һ����ȵĴ�д��ĸ(λ����ͬ����ĸ��ͬ) A~G �ֱ��ʾ����һ��������
����������Сʱ�����ҵ����ڵ��ַ�������������ң��ҵ���һ����ͬ�����ֻ���ĸ(0~9,A~N)(λ����ͬ����ĸ��ͬ),�ֱ��ʾ0~23
�������������ӣ��ں��������ַ����в��ң���һ����ȵ���ĸ����ĸ��ȵ�λ�þ��Ƿ���
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
				flag = i+1; // ����������� 
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
