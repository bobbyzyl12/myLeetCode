#include <iostream>
#include <vector>

using namespace std;
/*
	version 1: generate the vector as defined
	Runtime:3ms
	Beated:5.35%
*/
vector<vector<int>> generate(int numRows) {

	vector<vector<int>> res;		//the result of the function
	vector<int> tmp;				//the result of every row
	if (numRows == 0) {
		return res;
	}
	//initialize the first line
	tmp.push_back(1);				
	res.push_back(tmp);
	if (numRows == 1) {
		return res;
	}
	//initialize the second line
	tmp.push_back(1);
	res.push_back(tmp);
	if (numRows == 2) {
		return res;
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
	return res;
}

void main() {
	//test function
	vector<vector<int>> test = generate(5);
	for (int i = 0; i < test.size(); ++i) {
		for (int j = 0; j < test[i].size(); ++j) {
			cout << test[i][j] << "";
		}
		cout << endl;
	}
	system("pause");
}