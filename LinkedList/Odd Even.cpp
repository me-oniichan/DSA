//Problem Statement : https://leetcode.com/problems/odd-even-linked-list/submissions/855403948/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* newhead = new ListNode();
        ListNode* temphead= new ListNode();
        ListNode* ptr1 = newhead;
        ListNode* ptr2 = temphead;
        int i = 1;
        while(head != NULL){
            if (i&1){
                ptr1->next = head;
                ptr1 = ptr1->next;
            }
            else{
                ptr2->next = head;
                ptr2 = ptr2->next;
            }
            head = head->next;
            i++;
        }
        ptr2->next = NULL;
        ptr1->next = temphead->next;
        return newhead->next;
    }
}; 
 
int main(){

 
return 0;
}