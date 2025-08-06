#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;


class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int index = digits.size() - 1;
		bool flag = false;
		while (index >= 0) {
			if (digits[index] == 9) {
				flag = true;
				digits[index] = 0;
				index--;
			}
			else {
				digits[index] += 1;
				flag = false;
				return digits;
			}
		}
		if (flag) {
			digits.insert(digits.begin(), 1);
		}
		return digits;
	}
};

int main() {
	Solution s;
	vector<int> v = { 9,9 };
	vector<int> result = s.plusOne(v);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}