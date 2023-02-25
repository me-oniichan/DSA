#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prof = 0, selected = prices[0];
        for(int i: prices){
            if (selected < i) prof = max(prof, i-selected);
            else selected = i;
        }
        return prof;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}