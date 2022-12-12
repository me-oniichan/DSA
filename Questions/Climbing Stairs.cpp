//Problem Statement : https://leetcode.com/problems/climbing-stairs/

#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int prev = 0, req = 1;
        while(n--){
            req = prev+req;
            prev = req-prev; 
        }
        return req;
    }
}; 
 
int main(){
    
 
return 0;
}