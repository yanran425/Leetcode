#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int number = 0, flag = 0;
		for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
			if ((*it) == 0) {
				if (it == nums.begin()) {
					flag = 1;
				}
				else {
					vector<int>::iterator its = --it;
					nums.erase(++it);
					it = its;
					number++;
				}
			}
		}
		for (int i = 0; i < number; i++) {
			nums.push_back(0);
		}
		if (flag == 1) {
			nums.erase(nums.begin());
			nums.push_back(0);
		}
	}
};

int main() {
	Solution s;
	vector<int> v = { 0 };
	s.moveZeroes(v);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}

//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//class Solution {
//public:
//    void moveZeroes(vector<int>& nums) {
//        int n = nums.size(), left = 0, right = 0;
//        while (right < n) {
//            if (nums[right]) {
//                swap(nums[left], nums[right]);
//                left++;
//            }
//            right++;
//        }
//    }
//};
//int main() {
//	Solution s;
//	vector<int> v = { 0,1,0,3,5};
//	s.moveZeroes(v);
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
//		cout << *it << endl;
//	}
//	return 0;
//}