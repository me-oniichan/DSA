//Problem Statement : https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/771/

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* ptr = head;
        while(list1 != NULL && list2 != NULL){
            if(list1->val > list2->val){
                ptr->next = list2;
                list2 = list2->next;
            }
            else{
                ptr->next = list1;
                list1 = list1->next;
            }
            ptr= ptr->next;
        }

        if(list1 == NULL){
            ptr->next = list2;
        }
        else{
            ptr->next = list1;
        }

        return head->next;
    }
}; 
 
int main(){

 
return 0;
}