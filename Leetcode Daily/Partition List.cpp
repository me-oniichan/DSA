struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
	   ListNode *head1 = new ListNode(), *head2 = new ListNode();
	   ListNode *ptr1 = head1, *ptr2 = head2;
	   
	   while(head != nullptr){
		  if (head->val < x){
			 ptr1->next = head;
			 ptr1 = ptr1->next;
		  }
		  else {
			 ptr2->next = head;
			 ptr2 = ptr2->next;
		  }
		  head = head->next;
	   }
	   ptr2->next = nullptr;
	   ptr1->next = head2->next;
	   return head1->next;
    }
};
