#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <limits.h>
#include <stack>
using namespace std;

/*
	version 1: stack!
	Runtime:3ms
	Beated:15.80%
*/
bool isValid(string s) {
	stack<char> paren;
	for (char& c : s) {
		switch (c) {
		case '(':
		case '{':
		case '[': paren.push(c); break;
		case ')': if (paren.empty() || paren.top() != '(') return false; else paren.pop(); break;
		case '}': if (paren.empty() || paren.top() != '{') return false; else paren.pop(); break;
		case ']': if (paren.empty() || paren.top() != '[') return false; else paren.pop(); break;
		default:; // pass
		}
	}
	return paren.empty();
}

void main() {
	//initializion

	cout << "---------version 1----------" << endl;
	cout << "my divide :  " << isValid("()[]{}") << endl;
	system("pause");
}