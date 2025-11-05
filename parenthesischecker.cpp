#include <iostream>
#include <stack>
#include <string>
using namespace std;
int isMatching(char open, char close) {
 return (open == '(' && close == ')') ||
 (open == '[' && close == ']') ||
 (open == '{' && close == '}');
}
int isBalanced(const string& expr) {
 stack<char> s;
 for (char ch : expr) {
 if (ch == '(' || ch == '[' || ch == '{') {
 s.push(ch);
 } else if (ch == ')' || ch == ']' || ch == '}') {
 if (s.empty()) {
 return 0;
 }
 if (!isMatching(s.top(), ch)) {
 return 0;
 }
 s.pop();
}
 }
 if (s.empty()) {
 return 1;
 } else {
 return 0;
 }
}
int main() {
 string expression;
 cout << "Enter an expression: ";
 getline(cin, expression);
 if (isBalanced(expression))
 cout << "Balanced Expression" << endl;
 else
 cout << "Not Balanced Expression" << endl;
 return 0;
}
