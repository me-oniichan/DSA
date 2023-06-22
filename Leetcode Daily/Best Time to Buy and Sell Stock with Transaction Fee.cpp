#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int size = prices.size();
        int buy = -prices[0], sell = 0;

        for(size_t i=1; i < size; i++){
            int prevbuy = buy;
            buy = max(sell - prices[i], buy);
            sell = max(prevbuy+prices[i]-fee, sell);
        }

        return sell;
    }
};
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}