#include <bits/stdc++.h>
using namespace std;
/*
	一道简单的查找题，整行读入后再按照id排序
	最后按照规则去遍历查找即可 
*/
struct B{
	string id;
	string title;
	string author;
	string keys;
	string pr;
	string py;
} book[10005];
int n, m;
bool cmp(const struct B a, const struct B b){
	return a.id < b.id;
}
int main(){
	scanf("%d\n", &n);
	for (int i = 0; i < n; ++i){
		string s;
		getline(cin, s);
		book[i].id = s;
		getline(cin, s);
		book[i].title = s;
		getline(cin, s);
		book[i].author = s;
		getline(cin, s);
		book[i].keys = s;
		getline(cin, s);
		book[i].pr = s;
		getline(cin, s);
		book[i].py = s;
	}
	sort(book, book+n, cmp);
	scanf("%d\n", &m);
	while (m--){
		string s;
		getline(cin, s);
		int op = s[0]-'0';
		string key = s.substr(3);
		bool flag = false;
		cout << s << endl;
		for (int i = 0; i < n; ++i){
			switch(op) {
				case 1: 
					if (book[i].title == key){
						flag = true;
						cout << book[i].id << endl;
					}
					break;
				case 2: 
					if (book[i].author == key){
						flag = true;
						cout << book[i].id << endl;
					}
					break;
				case 3: 
					if (book[i].keys.find(key) != book[i].keys.npos){
						flag = true;
						cout << book[i].id << endl;
					}
					break;
				case 4: 
					if (book[i].pr == key){
						flag = true;
						cout << book[i].id << endl;
					}
					break;
				case 5: 
					if (book[i].py == key){
						flag = true;
						cout << book[i].id << endl;
					}
					break;
			}	
		}
		if (!flag) cout << "Not Found" << endl;
	}
	return 0;
}
