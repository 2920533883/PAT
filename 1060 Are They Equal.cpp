#include<bits/stdc++.h>
using namespace std;
 
string s1, s2, a1, a2;
 
string translate(int n, string s) {
	int size = s.size(), i = 0, count = 0;
	string temp;
	while (i < size && s[i] == '0') i++;
	if (s[i] == '.') {
		i++;
		for ( ; s[i] == '0'; i++) count--; // С��1��С����ѧ������10��ϵ���Ǹ��� 
		bool judge = false;							//��ֹ0.0����������
		for (; temp.size() < n && i < size; i++) {
				temp.push_back(s[i]);
				judge = true;
		}
		while (temp.size() < n) temp.push_back('0'); // ���㲹0 
		if(!judge) count = 0;
	}
	else {
		for(int j = i; s[j] != '.' && j < size; j++) count++;
		for (; s[i] != '.' && temp.size() < n && i < size; i++) temp.push_back(s[i]);
		if (temp.size() < n) i++;
		for (; i < size && temp.size() < n; i++) temp.push_back(s[i]);
		while (temp.size() < n) temp.push_back('0');
	}
	temp += ("*10^" + to_string(count));
	return temp;
}
 
int main() {
	int n = 0;
	scanf("%d", &n);
	cin >> s1 >> s2;
	a1 = translate(n, s1);
	a2 = translate(n, s2);
	if (a1 == a2) cout << "YES 0." << a1;
	else cout << "NO 0." << a1 << " 0." << a2;
	return 0;
}
