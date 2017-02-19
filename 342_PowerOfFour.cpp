#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/*
	version 1:devide until equals 1
	Runtime:3 ms
	Beated:29.31%
*/
bool isPowerOfFourD(double n) {
	if (n < 1) return false;
	else if (n == 1) {
		return true;
	}
	else {
		return isPowerOfFourD(n / 4);
	}
}

bool isPowerOfFour1(int n) {
	return isPowerOfFourD((double)n);
}

/*
	List out all the possiblities.
	Runtime: 3 ms
	Beated:29.31%
*/

bool isPowerOfFour3(int num) {
	switch (num) {
	case 1:
	case 4:
	case 16:
	case 64:
	case 256:
	case 1024:
	case 4096:
	case  16384:
	case 65536:
	case 262144:
	case 1048576:
	case 4194304:
	case 16777216:
	case 67108864:
	case 268435456:
	case 1073741824:
		return true;
	default:
		return false;
	}
}


/*
	View the reference.
	3 conditions in total :
	1) > 0
	2) is 2^n
	3) n-1 can be devided by 3
	Runtime: 52 ms
	Beated:57.81%
*/
void main() {

	cout << "---------version 1----------" << endl;
	cout << " n = -1  " << isPowerOfFour1(-1) << endl
		 << " n = 1  " << isPowerOfFour1(1) << endl
		 << " n = 2  " << isPowerOfFour1(2) << endl
		 << " n = 9  " << isPowerOfFour1(9) << endl
	     << " n = 16  " << isPowerOfFour1(16) << endl;

	cout << "---------version 2----------" << endl;
	cout << " n = -1  " << isPowerOfFour2(-1) << endl
		<< " n = 1  " << isPowerOfFour2(1) << endl
		<< " n = 2  " << isPowerOfFour2(2) << endl
		<< " n = 8  " << isPowerOfFour2(8) << endl
		<< " n = 16  " << isPowerOfFour2(16) << endl;

	system("pause");
}