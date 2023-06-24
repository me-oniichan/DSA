#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        cost.push_back(0);

        for(int i=2; i <= size; i++){
            cost[i] += min(cost[i-1], cost[i-2]);
        }
        return cost[size];
    }
}; 