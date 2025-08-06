#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<deque>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1)
        {
            return nums;
        }
        int size = nums.size();
        vector<int> res;
        deque<int> d;
        for (int i = 0; i < k; i++)
        {
            while (!d.empty() && nums[d.back()] <= nums[i])
            {
                d.pop_back();
            }
            d.push_back(i);
        }
        res.push_back(nums[d.front()]);
        for (int i = k; i < size; i++)
        {
            while (!d.empty() && nums[d.back()] <= nums[i])
            {
                d.pop_back();
            }
            d.push_back(i);
            while (d.front() <= i - k)
            {
                d.pop_front();
            }
            res.push_back(nums[d.front()]);
        }
        return res;
    }
};