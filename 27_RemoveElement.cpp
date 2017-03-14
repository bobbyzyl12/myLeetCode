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
	version 1: sort then overwrite move all data behind forward
	Runtime:6ms
	Beated:17.9%
*/
int removeElement(vector<int>& nums, int val) {
	int count = 0;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == val) count++;
		if (nums[i] > val) nums[i - count] = nums[i];		//overwrite
	}
	return nums.size() - count;
}


void main() {
	//initializion
	vector<int> nums;

	nums.push_back(8);
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(3);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(8);
	nums.push_back(3);
	nums.push_back(3);
	nums.push_back(8);
	nums.push_back(9);
	nums.push_back(12);
	nums.push_back(3);

	cout << "---------version 1----------" << endl;
	cout << removeElement(nums,3) <<endl;

	
	system("pause");
}