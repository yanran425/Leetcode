#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> v;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
			int left = i + 1, right = nums.size() - 1;
			if (nums[i] > 0) {
				break;
			}
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			while (left < right) {
				int sum = nums[i] + nums[left] + nums[right];
				if (sum == 0) {
					v.push_back(vector<int>{ nums[i], nums[left], nums[right] });
					left++;
					right--;
					while (nums[left - 1] == nums[left] && left < right) {
						left++;
					}
					while (nums[right + 1] == nums[right] && left < right) {
						right--;
					}
				}
				else if (sum < 0) {
					left++;
				}
				else {
					right--;
				}
			}
		}
		return v;
	}
};

int main() {
	Solution s;
	vector<int> v = { -1,0,1,2,-1,-4 };
	vector<vector<int>> res = s.threeSum(v);
	for (vector<vector<int>>::iterator it = res.begin(); it != res.end(); it++) {
		for (vector<int>::iterator its = (*it).begin(); its != (*it).end(); its++) {
			cout << (*its) << "\t";
		}
		cout << endl;
	}
	return 0;
}