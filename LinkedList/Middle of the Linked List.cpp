//Problem Statement : https://leetcode.com/problems/middle-of-the-linked-list/

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
    ListNode* middleNode(ListNode* head) {
        ListNode* ptr = head;
        int size=0;
        while (ptr){
            size++;
            ptr = ptr->next;
        }

        size/=2;
        while(size--) head = head->next;
        return head;
    }
};
 
int main(){

 
return 0;
}