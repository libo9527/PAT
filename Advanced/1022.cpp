#include <cstdio>
#include <map>
#include <string>
#include <iostream>
#include <set>
using namespace std;

map<string, set<int> > titleMap;
map<string, set<int> > authorMap;
map<string, set<int> > keyMap;
map<string, set<int> > publisherMap;
map<string, set<int> > yearMap;

void query(map<string, set<int> >& maps, string& condition) {
	if(maps.find(condition) == maps.end()) {
		printf("Not Found\n");
	} else {
		for(set<int>::iterator it = maps[condition].begin(); it != maps[condition].end(); it++) {
			printf("%07d\n", *it);
		}
	}
}

int main() {
	int n, m, id;
	string str;
	scanf("%d", &n);
	getchar();
	for(int i = 0; i < n; i++) {
		scanf("%d", &id);
		getchar();
		getline(cin, str);
		titleMap[str].insert(id);
		getline(cin, str);
		authorMap[str].insert(id);
		while(cin >> str) {
			keyMap[str].insert(id);
			char c = getchar();
			if(c == '\n') {
				break;
			}
		}
		getline(cin, str);
		publisherMap[str].insert(id);
		getline(cin, str);
		yearMap[str].insert(id);
	}
	scanf("%d", &m);
	getchar();
	int type;
	string condition;
	for(int i = 0; i < m; i++) {
		scanf("%d: ", &type);
		getline(cin, condition);
		printf("%d: ", type);
		cout << condition << endl;
		if(type == 1) {
			query(titleMap, condition);
		}
		if(type == 2) {
			query(authorMap, condition);
		}
		if(type == 3) {
			query(keyMap, condition);
		}
		if(type == 4) {
			query(publisherMap, condition);
		}
		if(type == 5) {
			query(yearMap, condition);
		}
	}
	return 0;
}