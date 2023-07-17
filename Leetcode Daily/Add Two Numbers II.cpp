#include <bits/stdc++.h>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<uint8_t> num1;
        stack<uint8_t> num2;
        for(; l1 != NULL; l1=l1->next) num1.push(l1->val);
        for(; l2 != NULL; l2=l2->next) num2.push(l2->val);
        ListNode *head = NULL;
        int carry=0;
        while(!num1.empty() || !num2.empty()){
            int sum=carry;
            if(!num1.empty()){
                sum+=num1.top();
                num1.pop();
            }
            if(!num2.empty()){
                sum+=num2.top();
                num2.pop();
            }
            head = new ListNode(sum%10, head);
            carry = sum/10;
        }
        if (carry){
            head = new ListNode(carry, head);
        }
        return head;
    }
};