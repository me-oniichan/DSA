//Problem Statement : https://leetcode.com/explore/interview/card/top-interview-questions-easy/97/dynamic-programming/572/

#include <bits/stdc++.h>
using namespace std;

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
    
 
return 0;
}