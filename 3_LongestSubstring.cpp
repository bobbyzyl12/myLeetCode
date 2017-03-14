#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;

/*
	version 1: using array to store the character position occured last time
	Runtime:25ms
	Beated:73.35%
*/
int lengthOfLongestSubstring1(string s) {
	vector<int> rec(256, -1);
	int maxLen = 0, start = -1;	//start records the position of the first charctor	last time
	if (s.size() == 0) {
		return maxLen;
	}
	for (int i = 0; i != s.size(); ++i) {
		if (rec[s[i]] > start) {	//repeated 
			start = rec[s[i]];		//change start
		}
		rec[s[i]] = i;
		maxLen = max(i - start, maxLen);
	}
	return maxLen;
}

void main() {

	cout << "---------version 1----------" << endl;
	cout << lengthOfLongestSubstring1("ausdaq") << endl;

	system("pause");
}