#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (vector<int>& tmp : matrix)
        {
            if (target < *(tmp.begin()))
            {
                return false;
            }
            else if (target > *(tmp.rbegin()))
            {
                continue;
            }
            else
            {
                if (binary_search(tmp.begin(), tmp.end(), target))
                    return true;
            }
        }
        return false;
    }
};