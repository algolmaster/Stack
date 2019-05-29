//
//  postfixExpression.cpp
//  Stack
//
//  Created by 신예지 on 21/05/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;
int priority(char c) {
    switch(c) {
        case '(': return 0;
        case '+': case '-': return 1;
        case '*': case '/': return 2;
    }
    return -1;
}

string postfixExpression(string input) {
    string postfix = "";
    stack<char> s;
    
    for(int i=0; i<input.length(); i++) {
        if(input[i]>='A' && input[i]<='Z') postfix += input[i]; //print operand
        else if(input[i]=='(') s.push(input[i]);    //push '('
        else if(input[i]==')') {    //pop until '('
            while(s.top()!='(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();    //remove '('
        }
        else {
            if(s.empty()) s.push(input[i]);
            else {
                while(!s.empty() && priority(s.top()) >= priority(input[i])) {
                    postfix += s.top();
                    s.pop();
                }
                s.push(input[i]);
            }
        }
    }
    
    while(!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    
    return postfix;
}

int main() {
    string input;
    cin >> input;
    
    cout << postfixExpression(input);
}
