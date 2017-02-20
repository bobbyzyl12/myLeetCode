#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

/*
	version 1: when is lower than yesterday, just buy in and sell it.
	Runtime:6 ms
	Beated:36.14%
*/
int maxProfit1(vector<int>& prices) {
	int size = prices.size();
	if (size == 0) {
		return 0;
	}
	int earn = 0;
	for (int i = 1; i < size; ++i) {
		if (prices[i] > prices[i - 1]) {
			earn += prices[i] - prices[i - 1];
		}
	}
	return earn;
}

void main() {
	vector<int> test;
	test.push_back(3);
	test.push_back(1);
	test.push_back(9);
	test.push_back(7);
	test.push_back(2);
	test.push_back(20);
	cout << "---------version 1----------" << endl;
	cout << maxProfit1(test) << endl;

	system("pause");
}