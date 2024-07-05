#include <bits/stdc++.h>
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head){
        vector<int> criticalPoints;
        
        if(head == nullptr || head->next == nullptr){
            return {-1, -1};
        }

        ListNode* temp = head->next;
        int i=0;
        int prev = head->val;
        while(temp != nullptr && temp->next != nullptr){
            if(prev < temp->val && temp->val > temp->next->val){
                criticalPoints.push_back(i);
            }
            else if(prev > temp->val && temp->val < temp->next->val){
                criticalPoints.push_back(i);
            }
            prev = temp->val;
            temp = temp->next;
            i++;
        }
        if(criticalPoints.size() < 2){
            return {-1, -1};
        }
        int minNodes = INT_MAX;
        int maxNodes = criticalPoints.back() - criticalPoints[0];
        for(int i=1; i<criticalPoints.size(); i++){
            minNodes = min(minNodes, criticalPoints[i] - criticalPoints[i-1]);
        }
        return {minNodes, maxNodes};
    }
};
