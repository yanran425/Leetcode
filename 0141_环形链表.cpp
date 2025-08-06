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
    bool hasCycle(ListNode* head) {
        if (head == nullptr)
        {
            return false;
        }
        ListNode* myhead1 = head;
        ListNode* myhead2 = head;
        while (myhead1->next != nullptr && myhead2->next != nullptr && myhead2->next->next != nullptr)
        {
            myhead1 = myhead1->next;
            myhead2 = myhead2->next->next;
            if (myhead1 == myhead2)
            {
                return true;
            }
        }
        return false;
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