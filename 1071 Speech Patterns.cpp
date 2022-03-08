#include <bits/stdc++.h>
using namespace std;
map<string, int> wordMap;
int main(){
	char a;
	string word = "";
	while (a = getchar()){
		if (isalnum(a) ){
			word += tolower(a);
		}
		else{
			if (word != "") wordMap[word]++;
			word = "";
			if (a == '\n') break;
		}
	}
	map<string, int> :: iterator i;
	string maxWord = "";
	int maxCount = 0;
	for (i = wordMap.begin(); i != wordMap.end(); ++i){
		if (maxCount == i->second){
			if (maxWord > i->first) maxWord = i->first;
		}
		else if (maxCount < i->second) {
			maxCount = i->second;
			maxWord = i->first;
		}
	}
	cout << maxWord << " " << maxCount << endl;
	return 0;
}
