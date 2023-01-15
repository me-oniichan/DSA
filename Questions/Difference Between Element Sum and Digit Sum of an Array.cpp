#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)
class Solution {
public:
    int digitsum(int n){
        int digit = 0;
        while(n){
            digit+=(n%10);
            n/=10;
        }
        return digit;
    }
    int differenceOfSum(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int digit = 0;
        for(int i : nums) digit+=digitsum(i);
        return abs(digit - sum);
    }
}; 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}