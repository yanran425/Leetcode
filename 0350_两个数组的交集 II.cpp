#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		vector<int>::iterator it1 = nums1.begin();
		vector<int>::iterator it2 = nums2.begin();
		vector<int> v;
		while (it1 != nums1.end() && it2 != nums2.end()) {
			if ((*it1) < (*it2)) {
				it1++;
			}
			else if ((*it1) > (*it2)) {
				it2++;
			}
			else {
				v.push_back(*it1);
				it1++;
				it2++;
			}
		}
		return v;
	}
};

class Print {
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

int main() {
	Solution s;
	vector<int> v1 = { 1,2,2,1 };
	vector<int> v2 = { 2,2 };
	vector<int> result = s.intersect(v1, v2);
	for_each(result.begin(), result.end(), Print());
	return 0;
}