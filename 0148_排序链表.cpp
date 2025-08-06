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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        vector<int> v;
        ListNode* myhead = head;
        while (myhead != nullptr)
        {
            v.push_back(myhead->val);
            myhead = myhead->next;
        }
        sort(v.begin(), v.end());
        myhead = head;
        int i = 0;
        while (myhead != nullptr)
        {
            myhead->val = v[i];
            i++;
            myhead = myhead->next;
        }
        return head;
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