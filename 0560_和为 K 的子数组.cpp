#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;
class Solution {
public:
    int subarraySum2(vector<int>& nums, int k) {
        int res = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            int sum = 0;
            for (int j = i; j >= 0; j--)
            {
                sum += nums[j];
                if (sum == k)
                {
                    res++;
                }
            }
        }
        return res;
    }
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> m;
        m.insert(pair<int, int>(0, 1));
        int res = 0;
        int presum = 0;
        for (auto& num : nums)
        {
            presum += num;
            if (m.find(presum - k) != m.end())
            {
                res += m[presum - k];
            }
            m[presum]++;

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