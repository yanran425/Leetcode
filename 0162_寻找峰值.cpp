#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++) {
			if (i == 0) {
				if (nums.size() == 1 || nums[i] > nums[i + 1]) {
					return 0;
				}
				else {
					continue;
				}
			}
			if (i == nums.size() - 1) {
				if (nums[i] > nums[i - 1]) {
					return i;
				}
				else {
					continue;
				}
			}
			if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
				return i;
			}
		}
		return -1;
	}
};

int main() {
	vector<int> v = { 3,4,5,1,2 };
	Solution s;
	cout << s.findPeakElement(v) << endl;
	return 0;
}