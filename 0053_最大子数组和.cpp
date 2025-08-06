#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int presum = 0, maxsum = INT_MIN;
        for (int i = 0; i < size; i++)
        {
            presum = presum >= 0 ? presum + nums[i] : nums[i];
            maxsum = presum > maxsum ? presum : maxsum;
        }
        return maxsum;
    }
    int maxSubArray2(vector<int>& nums) {
        int size = nums.size();
        if (size == 1)
        {
            return nums[0];
        }
        vector<int> presumv;
        int presum = 0, res = INT_MIN;
        presumv.push_back(presum);
        for (int i = 0; i < size; i++)
        {
            presum += nums[i];
            presumv.push_back(presum);
            int mini = *(min_element(presumv.begin(), presumv.end() - 1));
            res = presum - mini > res ? presum - mini : res;
        }
        return res;
    }
};
int main()
{
    vector<int> v;
    v.push_back(5);
    v.push_back(4);
    v.push_back(-1);
    v.push_back(7);
    v.push_back(8);
    Solution s;
    cout << s.maxSubArray(v) << endl;
    return 0;
}