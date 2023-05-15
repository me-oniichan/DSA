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
    ListNode* swapNodes(ListNode* head, int k) {
        int size=0;
        for(auto ptr = head; ptr != NULL; ptr = ptr->next){
            size++;
        }
        int rk = size-k;
        k--;
        ListNode *ptr1;
        ListNode *ptr2;
        auto ptr=head;
        for(int i=0; i < size; i++, ptr = ptr->next){
            if(i==k) ptr1 = ptr;
            if(i==rk) ptr2 = ptr;
        }
        swap(ptr1->val, ptr2->val);
        return head;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}