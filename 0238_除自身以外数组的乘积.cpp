#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> res(size, 0);
        for (int i = 0; i < size; i++)
        {
            res[i] = i == 0 ? 1 : res[i - 1] * nums[i - 1];
        }
        int tmp = 1;
        for (int i = size - 1; i >= 0; i--)
        {
            tmp = i == size - 1 ? 1 : tmp * nums[i + 1];
            res[i] *= tmp;
        }
        return res;
    }
    vector<int> productExceptSelf2(vector<int>& nums) {
        int size = nums.size();
        vector<int> before(size, 0);
        vector<int> tail(size, 0);
        for (int i = 0; i < size; i++)
        {
            before[i] = i == 0 ? 1 : before[i - 1] * nums[i - 1];
            tail[size - i - 1] = i == 0 ? 1 : tail[size - i] * nums[size - i];
        }
        for (int i = 0; i < size; i++)
            before[i] *= tail[i];
        return before;
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