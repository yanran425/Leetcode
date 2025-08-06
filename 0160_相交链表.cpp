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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        while (headA != nullptr)
        {
            ListNode* headB2 = headB;
            while (headB2 != nullptr)
            {
                if (headA == headB2)
                {
                    return headA;
                }
                headB2 = headB2->next;
            }
            headA = headA->next;
        }
        return headA;
    }
};
int main()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(2);

    Solution s;
    s.nextPermutation(v1);
    for (auto& i : v1)
        cout << i << endl;
    return 0;
}