//Problem Statement : https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/772/

#include <iostream>
#include <vector>
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
    bool isPalindrome(ListNode* head) {
        vector<int> vals;
        while(head){
            vals.push_back(head->val);
            head = head->next;
        }
        int size = vals.size();
        for(int i = 0; i<size/2; i++){
            if(vals[i] != vals[size-i-1]) return false;
        }
        return true;
    }
}; 
 
int main(){
    
 
return 0;
}