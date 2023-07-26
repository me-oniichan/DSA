#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(int speed, double hour, vector<int>&dist){
        double time_elapsed = 0;
        for(size_t i =0; i < dist.size()-1; i++){
            time_elapsed+= (dist[i]+speed-1)/speed;
            if(time_elapsed > hour) return false;
        }
        time_elapsed+= dist.back()/(double)speed;
        if(time_elapsed > hour) return false;
        return true;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left = 1, right = 10000000;
        if(!isValid(right, hour, dist)){
            return -1;
        }
        while(left < right){
            int mid = (left+right)/2;
            if(isValid(mid, hour, dist)){
               right = mid; 
            }
            else{
                left = mid+1;
            }
        }
        return left;
    }
};