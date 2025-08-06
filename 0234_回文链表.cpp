#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head->next == nullptr)
        {
            return true;
        }
        vector<int> v;
        while (head != nullptr)
        {
            v.push_back(head->val);
            head = head->next;
        }
        int size = v.size();
        int i = 0, j = size - 1;
        while (i < j)
        {
            if (v[i] != v[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
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