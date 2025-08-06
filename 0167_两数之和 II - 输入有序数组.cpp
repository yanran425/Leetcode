#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int left = 0, right = numbers.size() - 1;
		while (left < right) {
			if (numbers[left] + numbers[right] == target) {
				break;
			}
			else if (numbers[left] + numbers[right] < target)
			{
				left += 1;
			}
			else {
				right -= 1;
			}
		}
		return{ left + 1, right + 1 };
	}
};


int main() {
	Solution s;
	vector<int> v = { 2,7,11,15 };
	vector<int> result = s.twoSum(v, 9);
	for (vector<int>::iterator it = result.begin(); it != result.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}