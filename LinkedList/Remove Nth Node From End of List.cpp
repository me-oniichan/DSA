//Problem Statement : https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/603/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* ptr = head;
        while(ptr!=NULL){
            size++;
            ptr = ptr->next;
        }
        int index = size-n;
        
        ptr = head;
        if (index == 0){
            head = head->next;
            return head;
        }
        size = 1;
        while(size != index){
            size++;
            ptr = ptr->next;
        }
        
        ptr->next = ptr->next->next;
        return head;
    }
};