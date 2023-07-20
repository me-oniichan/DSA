#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n= req_skills.size(), m = people.size();
        unordered_map<string, short> strset;
        for(short i=0; i < n; i++) strset[req_skills[i]] = i;

        vector<short> personskill(m);
        for(short i=0; i < m; i++){
            for(string &s : people[i]){
                personskill[i] = 1<<strset[s];
            }
        }

        vector<long long> dp(1<<n, (1LL << m) -1);

        for(unsigned short skillmask = 1; skillmask < (1<<n); skillmask++){
            for (int i = 0; i < n; i++){
                unsi
            }
        }
    }
};