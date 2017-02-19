#include <iostream>
 
using namespace std;

/*
	version 1 : seperating different n and iteration
	Beated:15.82%
*/
double power(double x, int n) {
	if (n == 0) {
		return 1;
	}
	else if (x == 0) {
		return 0;
	}
	else if (n == 1) {
		return x;
	}
	else if (n < 0) {
		double tmp = pow(x, -n);
		if (tmp == 0) {
			x = 0;

		}
		else {
			x = 1 / pow(x, -n);
		}
		return x;
	}
	else if (n > 1) {
		x *= pow(x, n - 1);
		return x;
	}
}

/*
	version 2 : seperating different n and iteration 
	Added: when the n%2==0 then O(n) = lgn
	Beated:39.12%
*/
double power2(double x, int n) {
	if (n == 0) {
		return 1;
	}
	else if (n == 1) {
		return x;
	}
	else if(n%2==0){
		double tmp = pow(x, n / 2);
		return tmp*tmp;
	}
	else if (n < 0) {
		return 1 / pow(x, -n);;
	}
	else {
		return  pow(x, n - 1)*x;
	}
}

/*
	version 3 : seperating different n and iteration
	difference from version 2: try another way when n is odd
	Beated:39.12%
*/
double power3(double x, int n) {
	if (n == 0) {
		return 1;
	}
	else if (n < 0) {
		double tmp = pow(x, -n);
		if (tmp == 0) {
			return 0;

		}
		else {
			return 1 / tmp;
		}
	}
	else {
		if (n % 2 == 0) {
			return pow(x*x, n / 2);
		}
		return  x*pow(x*x, n / 2);
	}
}


void main() {
	
	cout << "---------version 1----------" << endl;
	for (int i = -3; i < 20; ++i) {
		cout << "pow (2," << i << ") : " << power(2, i) << endl;
	}
	cout << endl;

	
	cout << "---------version 2----------" << endl;
	for (int i = -3; i < 20; ++i) {
		cout << "pow (2," << i << ") : " << power2(2, i) << endl;
	}
	cout<< endl;

	cout << "---------version 3----------" << endl;
	for (int i = -3; i < 20; ++i) {
		cout << "pow (2," << i << ") : " << power3(2, i) << endl;
	}
	cout << endl;
	system("pause");
}