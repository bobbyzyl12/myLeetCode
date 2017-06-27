#include <iostream>
#include <vector>

using namespace std;
/*
	version 1: generate the vector as defined and using the previous code in 118
	Runtime:3ms
	Beated:3.04%
*/
vector<int>  getRow(int numRows) {
	vector<vector<int>> res;		//the result of the function
	vector<int> tmp;				//the result of every row
	numRows++;
	if (numRows == 0) {
		return tmp;
	}
	//initialize the first line
	tmp.push_back(1);				
	res.push_back(tmp);
	if (numRows == 1) {
		return tmp;
	}
	//initialize the second line
	tmp.push_back(1);
	res.push_back(tmp);
	if (numRows == 2) {
		return tmp;
	}

	for (int i = 2; i < numRows; ++i) {
		//clear the tmp vector
		tmp.clear();
		
		//if the current row is odd
		tmp.push_back(1);
		for (int j = 0; j < res[i - 1].size() - 1; ++j) {
			tmp.push_back(res[i - 1][j] + res[i - 1][j + 1]);
		}
		tmp.push_back(1);
		res.push_back(tmp);
	}
	return res[numRows-1];
}


/*
	version 2: just using a simple vector<int> to complete the function
	Runtime:3ms
	Beated:3.04%
*/
vector<int> getRow2(int rowIndex) {
	//initialize the size of the vector
	vector<int> res(rowIndex + 1);
	//initialize the first element
	res[0] = 1;

	for (int i = 0; i < res.size(); ++i)
	{
		for (int j = i; j > 0; --j)
		{
			res[j] += res[j - 1];
		}
	}
	return res;
}

void main() {
	//test function 1
	vector<int> test = getRow(5);
	for (int i = 0; i < test.size(); ++i) {
		cout << test[i] << " ";
	}
	cout << endl;

	//test function 2
	test = getRow2(5);
	for (int i = 0; i < test.size(); ++i) {
		cout << test[i] << " ";
	}
	system("pause");
}