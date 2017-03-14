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
	version 1: Traversal the numbers and find the target
	Runtime:6ms
	Beated:46.58%
*/
int searchInsert1(vector<int>& nums, int target) {
	if (nums.size() == 0) {
		return 0;
	}
	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] == target) {
			return i;
		}
		else if (nums[i] > target && i != 0) {
			return i;
		}
		else if (nums[i] > target && i == 0) {
			return 0;
		}
	}
	return nums.size();
}


/*
version 2: binary search
Runtime:9ms
Beated:13.2%
*/
int searchInsert2(vector<int>& nums, int target) {
	if (nums.size() == 0) {
		return 0;
	}
	int low = 0, high = nums.size() - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (nums[mid] == target)
		{
			return mid;
		}
		else if (nums[mid] < target) {
			low = mid +1;
		}
		else if (nums[mid] > target) {
			high = mid-1;
		}
	}
	return low;
}


void main() {
	//initializion
	vector<int> nums;

	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(8);
	nums.push_back(9);
	nums.push_back(12);

	cout << "---------version 1----------" << endl;
	cout << searchInsert1(nums,3) <<endl;

	cout << "---------version 2----------" << endl;
	cout << searchInsert2(nums, 3) << endl;
	system("pause");
}