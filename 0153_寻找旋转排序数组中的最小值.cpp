#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (r - l) / 2 + l;
            if (nums[mid] < nums[r]) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return nums[l];
    }
};

int main() {
    vector<int> v = { 3,4,5,1,2 };
    Solution s;
    cout << s.findMin(v) << endl;
    return 0;
}