#include <iostream>
#include <string>
#include <stack>

using namespace std;

string solution(string str) {
	stack<char> opt; //������
	stack<char> operand; //�ǿ�����

	string result="";
	char c_temp;
	int check = 0; //���� ����ȣ ����
	for (int j = 0; j < str.size(); j++) {
		char c = str[j];
		//cout << c;
		if (c == '(') {
			if(j!=0)
				check++;
			operand.push(c);
		}
		else if (c == ')') {
			check--;
			string s_temp;
			string op_temp;

			s_temp += operand.top();
			operand.pop();
			while ((c_temp = operand.top()) != '(') {
				s_temp += c_temp;
				operand.pop();
				op_temp += opt.top();
				opt.pop();
			}
			operand.pop();//��ȣ ����
			reverse(s_temp.begin(), s_temp.end());
			result += s_temp;
			result += op_temp;
		}
		else if (c == '*' || c == '/') {
			opt.push(c);
		}
		else if (c == '+' || c == '-') {
			char top = 'A';
			if(!opt.empty())
				top = opt.top();
			if (top == '*' || top == '/') { //�켱���� ���� ����ؾ� �� �� 
				string s_temp;
				string op_temp;
				s_temp += operand.top();
				operand.pop();
				while (opt.top() == '*' || opt.top() == '/') { //�켱���� �� ���� 
					s_temp += operand.top();
					operand.pop();
					op_temp += opt.top();
					opt.pop();
				}
				if (check == 0) {//���� ��ȣ ġ��
					while (!operand.empty()) {
						s_temp += operand.top();
						operand.pop();
						op_temp += opt.top();
						opt.pop();
					}
				}
				reverse(s_temp.begin(), s_temp.end());
				s_temp += op_temp;
				result += s_temp;
			}
			opt.push(c);
		}
		else
			operand.push(c);
	}
	string s_temp;
	string op_temp;
	while (!operand.empty()) {
		s_temp += operand.top();
		operand.pop();
	}
	while (!opt.empty()) {
		op_temp += opt.top();
		opt.pop();
	}
	reverse(s_temp.begin(), s_temp.end());
	s_temp += op_temp;
	result += s_temp;

	return result;
}
int main() {
	string str;
	cin >> str;

	string change = "(";
	change += str;
	change += ")";
	cout<<solution(str);
	
	return 0;
}