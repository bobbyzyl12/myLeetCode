#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

int hammingDistance(int x, int y) {			//last version
	int z = x ^ y;
	int n = 0;
	while (z > 0)
	{
		z &= (z - 1);
		++n;
	}
	return n;
}

int hammingDistance1(int x, int y) {			//version 1
	int z = x^y;
	int n = 0;
	while (z > 0) {
		if (z % 2 == 1)
			n++;
		z = z / 2;
	}

	return n;
}

void main(){
	
	cout << hammingDistance1(1,4)<<endl;
}
