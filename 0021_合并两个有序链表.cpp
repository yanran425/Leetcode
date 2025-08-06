#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<string>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode* p = new ListNode(0);
		ListNode* q = p;
		while (list1 != NULL && list2 != NULL) {
			if (list1->val < list2->val) {
				q->next = list1;
				q = q->next;
				list1 = list1->next;
			}
			else if (list1->val > list2->val) {
				q->next = list2;
				q = q->next;
				list2 = list2->next;
			}
			else {
				q->next = list1;
				q = q->next;
				list1 = list1->next;
				q->next = list2;
				q = q->next;
				list2 = list2->next;
			}
		}
		if (list1 != NULL) {
			q->next = list1;
		}
		if (list2 != NULL) {
			q->next = list2;
		}
		return p->next;
	}
};

int main() {
	ListNode lst1(4);
	ListNode lst2(2, &lst1);
	ListNode l1(1, &lst2);
	ListNode lst3(4);
	ListNode lst4(3, &lst3);
	ListNode l2(1, &lst4);
	Solution s;
	ListNode* result = s.mergeTwoLists(&l1, &l2);
	while (result != NULL) {
		cout << result->val << "\t";
		result = result->next;
	}
	cout << endl;
	return 0;
}