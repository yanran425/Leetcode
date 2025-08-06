#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		for (vector<vector<int>>::iterator it = matrix.begin(); it != matrix.end(); it++) {
			if (target <= (*it).back()) {
				vector<int>::iterator its = find((*it).begin(), (*it).end(), target);
				if (its == (*it).end()) {
					return false;
				}
				else {
					return true;
				}
			}
		}
		return false;
	}
};

int main() {
	vector<int> temp = { 1, 3, 5, 7 };
	vector<int> temp1 = { 10, 11, 16, 20 };
	vector<int> temp2 = { 23, 30, 34, 60 };
	vector<vector<int>> matrix;
	matrix.push_back(temp);
	matrix.push_back(temp1);
	matrix.push_back(temp2);
	Solution s;
	bool result = s.searchMatrix(matrix, 600);
	cout << result << endl;
	return 0;
}