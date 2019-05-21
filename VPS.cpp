#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool solution(string str) {
	stack<char> st;

	for (int j = 0; j < str.size(); j++) {
		char c = str[j];
		if (c == '(') st.push(c);
		else {
			if (st.empty())
				return false;
			st.pop();
		}
	}
	if (st.empty())
		return true;
	return false;
}
int main() {
	int c; //테스트 케이스
	cin >> c;

	string *str = new string[c];
	for (int i = 0; i < c; i++) {
		cin >> str[i];
	}
	for (int i = 0; i < c; i++) {
		if (solution(str[i]))
			cout << "YES"<<endl;
		else
			cout << "NO"<<endl;
	}
	return 0;
}