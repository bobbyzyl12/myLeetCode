#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

/*
	version 1:transvel the vector
	Runtime:9 ms
	Beated:15.02%
*/
int maxProfit1(vector<int>& prices) {
	int size = prices.size();
	if (size == 0) {
		return 0;
	}
	int min = prices[0],earn=0;
	for (int i = 0; i < size; ++i) {
		if (prices[i] < 0) {
			return 0;
		}
		if (prices[i] < min) {
			min = prices[i];
		}
		else if (prices[i] - min >earn) {
			earn = prices[i] - min;
		}
	}
	return earn;
}

/*
	version 2:use the library function instead of condition
	Runtime:6 ms
	Beated:43.97%
*/
int maxProfit2(vector<int>& prices) {
	if (prices.size() == 0) {
		return 0;
	}
	int min = prices[0], earn = 0;
	for (int i = 0; i <prices.size(); ++i) {
		min = std::min(min, prices[i]);
		earn = std::max(earn, prices[i] - min);
	}
	return earn;
}

/*
	version 3:use the operator instead of condition
	Runtime:6 ms
	Beated:43.97%
*/
int maxProfit3(vector<int>& prices) {
	if (prices.size() == 0) {
		return 0;
	}
	int min = prices[0], earn = 0;
	for (int i = 0; i <prices.size(); ++i) {
		min = min > prices[i] ? prices[i] : min;
		earn = earn > (prices[i] - min) ? earn : (prices[i] - min);
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

	cout << "---------version 2----------" << endl;
	cout << maxProfit2(test) << endl;

	cout << "---------version 3----------" << endl;
	cout << maxProfit3(test) << endl;

	system("pause");
}