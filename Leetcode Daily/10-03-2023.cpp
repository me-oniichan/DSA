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
    ListNode * head;
    int size=0;
    Solution(ListNode* head): head(head) {
        while(head!=NULL){
            size++;
            head=head->next;
        }
    }
    
    int getRandom() {
        int x = rand()%size;
        ListNode* ptr=head;
        while(x--){
            ptr= ptr->next;
        }
        return ptr->val;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}