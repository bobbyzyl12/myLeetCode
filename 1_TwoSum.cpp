#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;

/*
	Just record the res and compete every time
	Runtime:99ms
	Beated:37.40%
*/
vector<int> twoSum1(vector<int>& nums, int target) {
	vector<int> tmp;
	vector<int> res;
	if (nums.size() == 0) {
		return res;
	}
	for (int i = 0; i<nums.size(); ++i) {
		tmp.push_back(target - nums[i]);
		for (int j = 0; j<tmp.size(); ++j) {
			if (nums[i] == tmp[j] && i != j) {
				res.push_back(j);
				res.push_back(i);
				return res;
			}
		}
	}
	return res;
}

/*
	using map struct record every index
	Runtime:19 ms
	Beated:42.12%
*/
vector<int> twoSum2(vector<int>& nums, int target) {
	map<int, int> hash;
	vector<int> res;
	for (int i = 0; i < nums.size(); ++i) {
		int numberToFind = target - nums[i];

		//if numberToFind is found in map, return them
		if (hash.find(numberToFind) != hash.end()) {
			//+1 because indices are NOT zero based
			res.push_back(hash[numberToFind]);
			res.push_back(i);
			return res;
		}

		//number was not found. Put it in the map.
		hash[nums[i]] = i;
	}
}

void main() {
	vector<int> test;
	test.push_back(1);
	test.push_back(3);
	test.push_back(4);
	test.push_back(8);
	cout << "---------version 1----------" << endl;
	cout << twoSum1(test,7)[0]<< "  "<< twoSum1(test, 7)[1] << endl;
	
	cout << "---------version 2----------" << endl;
	cout << twoSum2(test, 7)[0] << "  " << twoSum2(test, 7)[1] << endl;

	system("pause");
}