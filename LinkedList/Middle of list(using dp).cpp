//Problem Statement : https://leetcode.com/problems/middle-of-the-linked-list/

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
    ListNode* middleNode(ListNode* head) {
        ListNode* ptr = head;
        vector<ListNode*> map;
        while (ptr){
            map.push_back(ptr);
            ptr = ptr->next;
        }

        return map[map.size()/2];
    }
};
 
int main(){

 
return 0;
}