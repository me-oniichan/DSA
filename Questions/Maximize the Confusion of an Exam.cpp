#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans=0;

        int start=0, end=0, size = answerKey.size();
        int trues=0, falses=0;
        for(; end < size; end++){
            if(answerKey[end]=='T') trues++;
            else falses++;

            int flips = min(trues, falses);
            // int confuse = max(trues, falses);
            if(flips <= k){
                ans=max(ans, end-start+1);
            }
            while(min(trues, falses) > k){
                if(answerKey[start]=='T') trues--;
                else falses--;
                start++;
            }
        }
        return ans;
    }
};