//Problem Statement : https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/773/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        //using floyd cycle method
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL){
             if (fast->next == slow) return true;
             fast = fast->next->next;
             slow = slow->next;
        }
        return false;
    }
};

 
int main(){
    
 
return 0;
}