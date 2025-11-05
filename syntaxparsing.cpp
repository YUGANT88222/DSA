#include <iostream>
#include <stack>
#include <string>
#include <cctype> // For isdigit
using namespace std;
bool isOperator(char ch) {
 return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}
int precedence(char op) {
 if (op == '^') return 3;
 if (op == '*' || op == '/') return 2;
 if (op == '+' || op == '-') return 1;
 return 0;
}
string infixToPostfix(const string& infix) {
 stack<char> s;
 string postfix;
 for (char ch : infix) {
 if (isdigit(ch)) {
 postfix += ch;
 } else if (ch == '(') {
 s.push(ch);
 } else if (ch == ')') {
 while (!s.empty() && s.top() != '(') {
 postfix += s.top();
s.pop();
 }
 if (!s.empty()) s.pop();
 } else if (isOperator(ch)) {
 while (!s.empty() && precedence(s.top()) >= precedence(ch) && s.top() != '(') {
 postfix += s.top();
 s.pop();
 }
 s.push(ch);
 }
 }
 while (!s.empty()) {
 postfix += s.top();
 s.pop();
 }
 return postfix;
}
// Function to evaluate postfix expression (digits only)
int evaluatePostfix(const string& postfix) {
 stack<int> s;
 for (char ch : postfix) {
 if (isdigit(ch)) {
 s.push(ch - '0'); // Convert char digit to int
 } else if (isOperator(ch)) {
 if (s.size() < 2) {
 cout << "Invalid postfix expression\n";
 return -1;
 }
 int b = s.top(); s.pop();
 int a = s.top(); s.pop();
 int result;
 switch (ch) {
 case '+': result = a + b; break;
 case '-': result = a - b; break;
 case '*': result = a * b; break;
 case '/':
cout << "Division by zero error\n";
 return -1;
 }
 result = a / b; break;
 case '^': {
 result = 1;
 for (int i = 0; i < b; i++) result *= a;
 break;
 }
 default:
 cout << "Unknown operator\n";
 return -1;
 }
 s.push(result);
 }
 }
 if (s.size() != 1) {
 cout << "Invalid postfix expression\n";
 return -1;
 }
 return s.top();
}
int main() {
 string expression;
 cout << "Enter an infix expression (digits and operators): ";
 getline(cin, expression);
 string postfix = infixToPostfix(expression);
 cout << "Postfix expression: " << postfix << endl;
 int result = evaluatePostfix(postfix);
 if (result != -1)
 cout << "Evaluation result: " << result << endl;
 return 0;
}
 if (b == 0) {
