#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> colindex;
        for (auto& i : matrix)
        {
            bool flag = false;
            for (int j = 0; j < i.size(); j++)
            {
                if (i.at(j) == 0)
                {
                    flag = true;
                    colindex.push_back(j);
                }
            }
            if (flag)
                fill(i.begin(), i.end(), 0);
        }
        for (auto i : colindex)
        {
            for (auto& j : matrix)
            {
                j[i] = 0;
            }
        }
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