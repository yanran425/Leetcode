#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int result = nums[0] + nums[1] + nums[2];
		for (vector<int>::iterator it = nums.begin(); it != nums.end() - 2; it++) {
			vector<int>::iterator it_left = it + 1;
			vector<int>::iterator it_right = nums.end() - 1;
			while (it_left != it_right) {
				int sum = *it + *it_left + *it_right;
				if (abs(sum - target) < abs(result - target)) {
					result = sum;
				}
				if (sum < target) {
					it_left++;
				}
				else if (sum > target) {
					it_right--;
				}
				else {
					return result;
				}
			}
		}
		return result;
	}
};

int main() {
	vector<int> nums;
	Solution s;
	nums.push_back(4);
	nums.push_back(0);
	nums.push_back(5);
	nums.push_back(-5);
	nums.push_back(3);
	nums.push_back(3);
	nums.push_back(0);
	nums.push_back(-4);
	nums.push_back(-5);
	int v = s.threeSumClosest(nums, -2);
	cout << v << endl;
	return 0;
}