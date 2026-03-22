#include <iostream>
#include <string>
#include <stack>
#include <queue>


using namespace std;

int main() {
	string str;
	getline(cin, str);

	bool isTag = 0;
	stack<char> s;
	queue<char> q;

	for (int i = 0; i < str.size(); i++) {
		// 태그 시작
		if (str[i] == '<') {
			// 스택 비우기
			while (!s.empty()) {
				cout << s.top();
				s.pop();
			}
			isTag = true; 
			q.push(str[i]); 
		} 
		// 태그 끝
		else if (str[i] == '>') {
			isTag = false; 
			q.push(str[i]); 
			// 큐 출력 
			while (!q.empty()) {
				cout << q.front(); 
				q.pop(); 
			}
		}
		else if (isTag) {
			q.push(str[i]); 
		}

		// 공백
		else if (str[i] == ' ') {
			while (!s.empty()) {
				cout << s.top();
				s.pop();
			}
			cout << ' ';
		}
		else { s.push(str[i]); }
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}


	return 0;

}