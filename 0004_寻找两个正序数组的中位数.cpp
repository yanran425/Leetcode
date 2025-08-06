#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> v;
		v.resize(nums1.size() + nums2.size());
		merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), v.begin());
		double res = 0.1;
		if ((nums1.size() + nums2.size()) % 2 == 0) {
			res = (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2.0;
		}
		else {
			res = v[v.size() / 2] * 1.0;
		}
		return res;
	}
};

int main() {
	Solution s;
	vector<int> v1 = { 1,3 };
	vector<int> v2 = { 2 };
	double res = s.findMedianSortedArrays(v1, v2);
	cout << res << endl;;
	return 0;
}


