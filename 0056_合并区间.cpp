#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if ((intervals.size() == 0) || (intervals.size() == 1))
        {
            return intervals;
        }
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
            });
        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= end)
            {
                end = max(intervals[i][1], end);
            }
            else
            {
                vector<int> tmp;
                tmp.push_back(start);
                tmp.push_back(end);
                res.push_back(tmp);
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        vector<int> tmp;
        tmp.push_back(start);
        tmp.push_back(end);
        res.push_back(tmp);
        return res;
    };
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