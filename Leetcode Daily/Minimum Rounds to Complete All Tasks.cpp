//Problem Statement : https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> m;
        for(int i : tasks) m[i]++;
        int count = 0;

        for(auto i : m){
            if (i.second == 1) return -1;

            int r = i.second%3;
            if (r==1){
                count+= i.second/3 -1;
                count+=2;
            }
            else{
                count+=i.second/3;
                count+=r/2;
            }
         }
        return count;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}