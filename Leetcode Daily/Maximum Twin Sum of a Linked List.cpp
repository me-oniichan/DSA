#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> vec;
        ListNode *fast = head, *slow = head;
        for(; fast!=NULL && fast->next!=NULL; fast = fast->next->next, slow = slow->next){
            vec.push_back(slow->val);
        }
        int i = vec.size()-1;
        int maxsum=0;
        for(;i>=0; i--, slow = slow->next){
            maxsum = max(vec[i]+slow->val, maxsum);
        }
        return maxsum;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}