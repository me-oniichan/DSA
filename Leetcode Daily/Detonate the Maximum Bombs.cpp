#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int size = bombs.size();
        int maxans = 0;

        for(int i=0; i < size; i++){
            vector<bool> visited(size);
            queue<int> q;
            q.push(i);
            int tempans = 1;
            visited[i]=1;
            
            while(!q.empty()){
                int bomb = q.front();
                q.pop();

                for(int j = 0; j < size; j++){
                    if(!visited[j]){
                        long long x = bombs[bomb][0]-bombs[j][0],y=bombs[bomb][1]-bombs[j][1];
                        if(x*x+y*y <= (long long)bombs[bomb][2]*bombs[bomb][2]){
                            visited[j] = 1;
                            q.push(j);
                            tempans++;
                        }

                    }
                }
            }
            maxans = max(maxans, tempans);
        }
        return maxans;
    }
};