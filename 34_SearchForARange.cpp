#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/*
	version 1: traversal the whole vector and find where the target should be 
*/
vector<int> searchRange1(vector<int>& nums, int target) {
	vector<int> res;
	bool find = false;
	int size = nums.size();
	if (size == 0) {
		res.push_back(-1);
		res.push_back(-1);
		return res;
	}
	for (int i = 0; i < size; ++i) {
		if (nums[i] == target) {
			if (!find) {
				res.push_back(i);
				res.push_back(i);
				find = true;
			}
			else {
				res[1] = i;
			}
		}
	}
	if (!find) {
		res.push_back(-1);
		res.push_back(-1);
	}
	return res;
}


/*
	version 2: traversal the whole vector and find where the target should be. When find the last,break
*/
vector<int> searchRange2(vector<int>& nums, int target) {
	vector<int> res;
	bool find = false;
	int size = nums.size();
	if (size == 0) {
		res.push_back(-1);
		res.push_back(-1);
		return res;
	}
	for (int i = 0; i < nums.size(); ++i) {
		if (!find && nums[i] == target) {
			res.push_back(i);
			res.push_back(i);
			find = true;
		}
		else if (!find && nums[i] != target) {
			continue;
		}
		else if (find && nums[i] == target) {
			res[1] = i;
		}
		else if ((find && nums[i] != target)) {
			break;
		}
	}
	if (!find) {
		res.push_back(-1);
		res.push_back(-1);
	}
	return res;
}
	

void main() {
	
	vector<int> a;
	a.push_back(1);
	a.push_back(3);
	a.push_back(4);
	a.push_back(4);
	a.push_back(5);
	a.push_back(6);
	a.push_back(6);
	a.push_back(6);

	for (int i = 0; i < a.size(); ++i) {
		cout << " " << a[i] << " ";
	}
	cout << endl<<endl;

	cout << "---------version 1----------" << endl;
	cout << "target = 1  " << searchRange1(a, 1)[0] << " " << searchRange1(a, 1)[1] << endl
		 << "target = 3  " << searchRange1(a, 3)[0] << " " << searchRange1(a, 3)[1] << endl
		 << "target = 4  " << searchRange1(a, 4)[0] << " " << searchRange1(a, 4)[1] << endl
		 << "target = 6  " << searchRange1(a, 6)[0] << " " << searchRange1(a, 6)[1] << endl
		 << "target = 7  " << searchRange1(a, 7)[0] << " " << searchRange1(a, 7)[1] << endl;

	cout << "---------version 2----------" << endl;
	cout 
		 << "target = 1  " << searchRange2(a, 1)[0] << " " << searchRange2(a, 1)[1] << endl
		 << "target = 3  " << searchRange2(a, 3)[0] << " " << searchRange2(a, 3)[1] << endl
		 << "target = 4  " << searchRange2(a, 4)[0] << " " << searchRange2(a, 4)[1] << endl
		 << "target = 6  " << searchRange2(a, 6)[0] << " " << searchRange2(a, 6)[1] << endl
		 << "target = 7  " << searchRange2(a, 7)[0] << " " << searchRange2(a, 7)[1] << endl;
	cout << endl;

	system("pause");
}
