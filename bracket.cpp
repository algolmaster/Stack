//
//  bracket.cpp
//  Stack
//
//  Created by 신예지 on 21/05/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

string isVPS(string str) {
    string check = "NO";
    stack<char> bracket;
    
    if(str[0]==')' || str.length()%2 == 1) return check;
    
    for(int i=0; i<str.length(); i++) {
        if (str[i]=='(') bracket.push('(');
        else {
            if(bracket.empty()) return check;
            else bracket.pop();
        }
    }
    if(bracket.empty()) check = "YES";
    
    return check;
}

int main() {
    int tc;
    cin >> tc;
    
    for(int i=0; i<tc; i++) {
        string str;
        cin >> str;
        
        cout << isVPS(str) << endl;
    }
}
