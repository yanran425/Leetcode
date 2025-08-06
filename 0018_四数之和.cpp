#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<set>

using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> vr;

		if (nums.size() <= 3) {
			return vr;
		}

		sort(nums.begin(), nums.end());
		for (vector<int>::iterator it = nums.begin(); it != nums.end() - 3; it++) {
			for (vector<int>::iterator it2 = it + 1; it2 != nums.end() - 2; it2++) {
				if ((long long)*it + *it2 + *(it2 + 1) + *(it2 + 2) > target) {
					continue;
				}
				if ((long long)*it + *it2 + *(nums.end() - 1) + *(nums.end() - 2) < target) {
					continue;
				}

				vector<int>::iterator it_left = it2 + 1;
				vector<int>::iterator it_right = nums.end() - 1;
				while (it_left != it_right) {
					long long sum = (long long)*it + *it2 + *it_left + *it_right;
					if (sum < target) {
						it_left++;
					}
					else if (sum > target) {
						it_right--;
					}
					else {
						vector<int> v = { *it,*it2,*it_left,*it_right };
						vr.push_back(v);
						it_left++;
					}
				}
			}
		}
		set<vector<int>> s;
		for (vector<vector<int>>::const_iterator it = vr.begin(); it != vr.end(); it++) {
			s.insert(*it);
		}
		vr.clear();
		for (set<vector<int>>::const_iterator it = s.begin(); it != s.end(); it++) {
			vr.push_back(*it);
		}
		return vr;
	}
};


int main() {
	vector<int> v = { 1,0,-1,0,-2,2 };

	Solution s;
	vector<vector<int>> vr = s.fourSum(v, 0);
	for (vector<vector<int>>::const_iterator it = vr.begin(); it != vr.end(); it++) {
		for (vector<int>::const_iterator it2 = (*it).begin(); it2 != (*it).end(); it2++) {
			cout << *it2 << endl;
		}
		cout << endl;
	}
	return 0;
}