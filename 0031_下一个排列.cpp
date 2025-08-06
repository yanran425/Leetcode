#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int i = size - 2;
        bool flag = false;
        for (i = size - 2; i >= 0; i--)
        {
            int rindex = size - 1;
            int rvalue = 101;
            for (int j = i + 1; j < size; j++)
            {
                if ((nums[j] > nums[i]) && (nums[j] < rvalue))
                {
                    rvalue = nums[j];
                    rindex = j;
                    flag = true;
                }
            }
            if (flag)
            {
                int tmp = nums[i];
                nums[i] = nums[rindex];
                nums[rindex] = tmp;
                break;
            }
        }
        sort(nums.begin() + i + 1, nums.end());
        return;
    }
};
int main()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(2);

    Solution s;
    s.nextPermutation(v1);
    for (auto& i : v1)
        cout << i << endl;
    return 0;
}