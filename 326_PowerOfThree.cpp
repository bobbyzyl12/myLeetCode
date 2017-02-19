#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/*
	version 1:devide until equals 1
	Runtime:58 ms
	Beated:52.33%
*/
bool isPowerOfThreeD(double n) {
	if (n < 1) return false;
	else if (n == 1) {
		return true;
	}
	else {
		return isPowerOfThreeD(n / 3);
	}
}

bool isPowerOfThree1(int n) {
	return isPowerOfThreeD((double)n);
}

/*
	View the reference. 3^19, 3^20 = 3486784401 > 2^31 - 1
	Runtime: 52 ms
	Beated:57.81%
*/

bool isPowerOfThree2(int n) {
	int const Max3PowerInt = 1162261467; 
	if (n <= 0 || n > Max3PowerInt) return false;
	return Max3PowerInt % n == 0;
}

void main() {

	cout << "---------version 1----------" << endl;
	cout << " n = -1  " << isPowerOfThree1(-1) << endl
		 << " n = 1  " << isPowerOfThree1(1) << endl
		 << " n = 2  " << isPowerOfThree1(2) << endl
		 << " n = 9  " << isPowerOfThree1(9) << endl
	     << " n = 16  " << isPowerOfThree1(16) << endl;

	cout << "---------version 2----------" << endl;
	cout << " n = -1  " << isPowerOfThree2(-1) << endl
		<< " n = 1  " << isPowerOfThree2(1) << endl
		<< " n = 2  " << isPowerOfThree2(2) << endl
		<< " n = 9  " << isPowerOfThree2(9) << endl
		<< " n = 16  " << isPowerOfThree2(16) << endl;

	system("pause");
}