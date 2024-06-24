#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int satisfied = 0;
        for(int i = 0; i < n; i++){
            if(grumpy[i] == 0){
                satisfied += customers[i];
            }
        }
        int maxSatisfied = 0;
        for(int i = 0; i < minutes; i++){
            if(grumpy[i] == 1){
                maxSatisfied += customers[i];
            }
        }
        int temp = maxSatisfied;
        for(int i = minutes; i < n; i++){
            if(grumpy[i] == 1){
                temp += customers[i];
            }
            if(grumpy[i - minutes] == 1){
                temp -= customers[i - minutes];
            }
            maxSatisfied = max(maxSatisfied, temp);
        }
        return satisfied + maxSatisfied;
    }
};
