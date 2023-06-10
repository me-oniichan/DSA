#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int leftelem = index, rightelem = n-index;
        int minsum = 0, rqsum = maxSum;

        while(minsum < rqsum){
            int midsum = (minsum+rqsum+1)/2;
            long long leftsum, rightsum;
            if(leftelem < midsum){
                leftsum = (long long)(2*midsum - leftelem)*(leftelem+1)/2;
            }
            else{
                leftsum = (long long)(midsum+1)*(midsum)/2 + leftelem - midsum+1;
            }

            if(midsum > rightelem){
                rightsum = (long long)(2*midsum - rightelem+1)*(rightsum+1)/2;
            }
            else{
                rightsum = (long long)(midsum)*(midsum+1)/2 + rightelem - midsum;
            }

            if(leftsum+rightsum - midsum <= maxSum) minsum = midsum;
            else rqsum = midsum-1;
        }
        return minsum;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}