//Problem Statement : https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/560/

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
    ListNode* reverseList(ListNode* head) {
        ListNode* next = head;
        ListNode *prev = NULL;
        while(next!=NULL){
            head = next;
            next = head->next;
            head->next = prev;
            prev = head;
        }
        return head;

    }
};

int main(){

 
return 0;
}