//Problem Statement : https://leetcode.com/explore/interview/card/top-interview-questions-easy/102/math/744/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    int countPrimes(int n) {
        if (!n || n==1) return false;
        vector<bool> arr(n-1);
        arr[0]=1;

        for(int i = 2; i*i < n; i++){
            if(arr[i-1] == 0){
                for(int j =i; j*i < n;j++) arr[i*j-1] =1;
            }
        }
        return count(arr.begin(), arr.end(), 0);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution sol;
    cout<<sol.countPrimes(1);
return 0;
}