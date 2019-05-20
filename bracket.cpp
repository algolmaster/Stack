#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isVPS(string input) {
    stack<int> s;

    char OPEN = '(';
    char CLOSE = ')';

    for (int i = 0; i < input.length(); i++) {
        if (input[i] == OPEN) s.push(1);
        else if (input[i] == CLOSE) {
            if (s.empty()) return false;
            else s.pop();
        }
        else return false;
    }

    if (s.empty()) return true;
    else return false;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;

        if (isVPS(input)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}
