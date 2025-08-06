#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        int res = nums[0];
        if (size == 1)
            return res;
        size = size % 2 == 0 ? size / 2 : size / 2 + 1;
        map<int, int> m;
        for (auto& num : nums)
        {
            m[num]++;
            if (m[num] == size)
            {
                res = num;
                break;
            }
        }
        return res;
    }
};
int main()
{
    vector<vector<int>> vn;
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    //v1.push_back(3);
    vn.push_back(v1);

    vector<int> v2;
    v2.push_back(8);
    v2.push_back(10);
    //v2.push_back(6);
    vn.push_back(v2);

    vector<int> v3;
    v3.push_back(2);
    v3.push_back(6);
    vn.push_back(v3);

    vector<int> v4;
    v4.push_back(15);
    v4.push_back(18);
    vn.push_back(v4);

    Solution s;
    vector<vector<int>> res = s.merge(vn);
    for (auto& i : res)
        cout << i[0] << " " << i[1] << endl;
    return 0;
}