#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return 1;
        }
        else if (nums.size() == 0)
        {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int res = 0, num = 1;
        int start = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == start + 1)
            {
                start += 1;
                num++;
            }
            else if (nums[i] == start)
            {

            }
            else
            {
                start = nums[i];
                res = res > num ? res : num;
                num = 1;
            }
        }
        res = res > num ? res : num;
        return res;
    }
};
int main()
{
    vector<int> v;
    v.push_back(0);
    v.push_back(3);
    v.push_back(7);
    v.push_back(2);
    v.push_back(5);
    v.push_back(8);
    v.push_back(4);
    v.push_back(6);
    v.push_back(0);
    v.push_back(1);
    Solution s;
    int res = s.longestConsecutive(v);
    cout << res << endl;
    return 0;
}
