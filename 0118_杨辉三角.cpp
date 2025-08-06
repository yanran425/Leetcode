#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.reserve(numRows);
        if (numRows >= 1)
        {
            vector<int> tmp = { 1 };
            res.push_back(tmp);
        }
        if (numRows >= 2)
        {
            vector<int> tmp = { 1, 1 };
            res.push_back(tmp);
        }
        if (numRows >= 3)
        {
            for (int i = 2; i <= numRows - 1; i++)
            {
                vector<int> tmp = { 1 };
                for (int j = 0; j <= res[i - 1].size() - 2; j++)
                {
                    tmp.push_back(res[i - 1][j] + res[i - 1][j + 1]);
                }
                tmp.push_back(1);
                res.push_back(tmp);
            }
        }
        return res;
    }
};