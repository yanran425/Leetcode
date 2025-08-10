#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int flag = 1;
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            if (nums[i] == flag)
            {
                flag++;
            }
            else if (nums[i] > flag)
            {
                return flag;
            }
        }
        return flag;
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
