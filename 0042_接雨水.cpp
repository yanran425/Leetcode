#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int leftmax = 0;
        vector<int> leftmaxv;
        int rightmax = 0;
        vector<int> rightmaxv;
        int res = 0;
        int size = height.size();
        for (int i = 0; i < size; i++)
        {
            if (height[i] > leftmax)
            {
                leftmax = height[i];
            }
            leftmaxv.push_back(leftmax);
        }
        for (int i = size - 1; i >= 0; i--)
        {
            if (height[i] > rightmax)
            {
                rightmax = height[i];
            }
            rightmaxv.push_back(rightmax);
        }
        for (int i = 0; i < size; i++)
        {
            int tmp = min(leftmaxv[i], rightmaxv[size - i - 1]) - height[i];
            res += tmp;
        }
        return res;
    }
    int trap2(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftmax = 0, rightmax = 0, res = 0;
        while (left < right)
        {
            if (height[left] < height[right])
            {
                leftmax = height[left] > leftmax ? height[left] : leftmax;
                res = height[left] > leftmax ? res : res + leftmax - height[left];
                left++;
            }
            else {
                rightmax = height[right] > rightmax ? height[right] : rightmax;
                res = height[right] > rightmax ? res : res + rightmax - height[right];
                right--;
            }
        }
        return res;
    }
};
int main()
{
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(2);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);
    Solution s;
    int res = s.trap(v);
    cout << res << endl;
    return 0;
}