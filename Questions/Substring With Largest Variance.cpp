#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestVariance(string s) {
        array<int, 26> counter={0};
        for(char &ch : s) counter[ch-'a']++;

        int maxvarience=0;
        for(size_t i=0; i < 26; i++){
            for(size_t j=0; j < 26; j++){
                if(i==j || counter[i]==0 || counter[j]==0) continue;

                char p1 = 'a'+i, p2='a'+j;
                int p1count=0, p2count=0;
                int p2left = counter[j];

                for(char c : s){
                    if(c==p1) p1count++;
                    else if(c==p2){
                        p2count++;
                        p2left--;
                    }

                    if(p2count > 0){
                        maxvarience = max(maxvarience, p1count-p2count);
                    }

                    if(p1count < p2count && p2left > 0){
                        p1count = p2count=0;
                    }
                }
            }
        }
        return maxvarience;
    }
};