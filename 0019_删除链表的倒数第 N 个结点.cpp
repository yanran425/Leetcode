#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n == 0)
        {
            return head;
        }
        if (head->next == nullptr)
        {
            return nullptr;
        }
        ListNode* myfast = head;
        ListNode* myslow = head;
        for (int i = 0; i < n; i++)
        {
            myfast = myfast->next;
        }
        if (myfast == nullptr)
        {
            return head->next;
        }
        while (myfast->next != nullptr)
        {
            myfast = myfast->next;
            myslow = myslow->next;
        }
        ListNode* tmp = myslow->next->next;
        myslow->next = tmp;
        return head;
    }
};
int main()
{
    ListNode l5(5);
    ListNode l4(4, &l5);
    ListNode l3(3, &l4);
    ListNode l2(2, &l3);
    ListNode l1(1, &l2);
    Solution s;
    ListNode* res = s.reverseKGroup(&l1, 2);
    while (res != nullptr)
    {
        cout << res->val << endl;
        res = res->next;
    }

    return 0;
}