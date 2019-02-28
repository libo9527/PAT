#include <iostream>
#include <cstring>
#include <map>
#include <string>
using namespace std;

bool check(char c) {
	if((c >= '0' && c <= '9') ||
	        (c >= 'a' && c <= 'z') ||
	        (c >= 'A' && c <= 'Z')) {
		return true;
	}
	return false;
}

int main() {
	string str;
	getline(cin, str);
	map<string, int> count;
	int i = 0;
	while(i < str.length()) {
		string words;
		while(i < str.length() && check(str[i]) == true) {
			if(str[i] >= 'A' && str[i] <= 'Z') {
				str[i] = str[i] + 32;
			}
			words += str[i];
			i++;
		}
		if(words != "") {
			if(count.find(words) != count.end()) {
				count[words]++;
			} else {
				count[words] = 1;
			}
		}
		while(i < str.length() && check(str[i]) == false) {
			i++;
		}
	}
	int num = 0;
	string ans;
	for(map<string, int>::iterator it = count.begin(); it != count.end(); it++) {
		if(it->second > num) {
			num = it->second;
			ans = it->first;
		}
	}
	cout << ans << " " << num;
	return 0;
}