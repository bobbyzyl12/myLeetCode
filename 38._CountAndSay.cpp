#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <limits.h>
#include <stack>
#include <string>
using namespace std;

/*
	version 1: using recursion and genenrate as the question require
	Runtime:3ms
	Beated:34.50%
*/
string countAndSay(int n) {
	if (n == 1) return "1";
		string s = countAndSay(n - 1);
		char tmp = s[0];
		int count = 1;
		string res;
		for (int i = 1; i < s.size(); ++i) {
			if (tmp == s[i]) {
				count++;
			}
			else {
				res.push_back(count + 48);
				res.push_back(tmp);
				tmp = s[i];
				count = 1;
			}
		}
		
		res.push_back(count + 48);
		res.push_back(tmp);
		return res;
}

void main() {
	//initializion

	cout << "---------version 1----------" << endl;
	cout << countAndSay(5) <<endl;
	system("pause");
}