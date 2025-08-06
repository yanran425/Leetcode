#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		vector<char> v1;
		vector<char> v2;
		vector<char> v3;
		for (int i = 0; i < 9; i++) {
			v1.clear();
			v2.clear();
			v3.clear();
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') {
					v1.push_back(board[i][j]);
				}
			}
			if (v1.size() > 1) {
				sort(v1.begin(), v1.end());
				vector<char>::iterator it = adjacent_find(v1.begin(), v1.end());
				if (it != v1.end()) {
					return false;
				}
			}

			for (int j = 0; j < 9; j++) {
				if (board[j][i] != '.') {
					v2.push_back(board[j][i]);
				}
			}
			if (v2.size() > 1) {
				sort(v2.begin(), v2.end());
				vector<char>::iterator it = adjacent_find(v2.begin(), v2.end());
				if (it != v2.end()) {
					return false;
				}
			}

			int m = i / 3 * 3, n = (i % 3) * 3;
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					if (board[m + j][n + k] != '.') {
						v3.push_back(board[m + j][n + k]);
					}
				}
			}
			if (v3.size() > 1) {
				sort(v3.begin(), v3.end());
				vector<char>::iterator it = adjacent_find(v3.begin(), v3.end());
				if (it != v3.end()) {
					return false;
				}
			}
		}
		return true;
	}
};

int main() {
	Solution s;
	vector<vector<char>> v = {
		{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'} };
	vector<vector<char>> v2 = {
		{'.', '.', '.', '.', '5', '.', '.', '1', '.'},
		{'.', '4', '.', '3', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '3', '.', '.', '1'},
		{'8', '.', '.', '.', '.', '.', '.', '2', '.'},
		{'.', '.', '2', '.', '7', '.', '.', '.', '.'},
		{'.', '1', '5', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '2', '.', '.', '.'},
		{'.', '2', '.', '9', '.', '.', '.', '.', '.'},
		{'.', '.', '4', '.', '.', '.', '.', '.', '.'} };
	vector<vector<char>> v3 = {
		{'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'} };
	bool result = s.isValidSudoku(v3);
	cout << result << endl;
	return 0;
}