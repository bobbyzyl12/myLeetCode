#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/*
	version 1:devide until equals 1
	Runtime:3 ms
	Beated:28.91%
*/
bool isPowerOfTwoD(double n) {
	if (n < 1) return false;
	else if (n == 1) {
		return true;
	}
	else {
		return isPowerOfTwoD(n / 2);
	}
}

bool isPowerOfTwo1(int n) {
	return isPowerOfTwoD((double)n);
}

/*
	View the reference and review how integer is defined in binary.
	Eg. 100 & 011 =  000 , power of 2 is always like  100 1000  10  1 , so !(n&(n-1)) always true;
	Runtime: 6 ms
	Beated:3.31%
*/

bool isPowerOfTwo2(int n) {
	return n > 0 && !(n&(n - 1));
}

void main() {

	cout << "---------version 1----------" << endl;
	cout << " n = -1  " << isPowerOfTwo1(-1) << endl
		 << " n = 1  " << isPowerOfTwo1(1) << endl
		 << " n = 2  " << isPowerOfTwo1(2) << endl
		 << " n = 10  " << isPowerOfTwo1(10) << endl
	     << " n = 16  " << isPowerOfTwo1(16) << endl;

	cout << "---------version 2----------" << endl;
	cout << " n = -1  " << isPowerOfTwo2(-1) << endl
		<< " n = 1  " << isPowerOfTwo2(1) << endl
		<< " n = 2  " << isPowerOfTwo2(2) << endl
		<< " n = 10  " << isPowerOfTwo2(10) << endl
		<< " n = 16  " << isPowerOfTwo2(16) << endl;

	system("pause");
}