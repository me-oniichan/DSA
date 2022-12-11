//Problem Statement : https://leetcode.com/explore/interview/card/top-interview-questions-easy/96/sorting-and-searching/774/

#include <iostream>
using namespace std;

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n;
        while(low<high){
            int mid = (low+high)/2;
            if (isBadVersion(mid)){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return high;
    }
}; 
 
int main(){
    
 
return 0;
}