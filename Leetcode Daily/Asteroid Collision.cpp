#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(int i : asteroids){
            while(true){
                if(ans.empty()){
                    ans.push_back(i);
                    break;
                }
                int top = ans.back();
                if(i < 0 && top > 0){
                    if(i*-1 > top) {
                        ans.pop_back();
                        continue;
                    }
                    else if(i*-1 == top){
                        ans.pop_back();
                    }
                }else ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};