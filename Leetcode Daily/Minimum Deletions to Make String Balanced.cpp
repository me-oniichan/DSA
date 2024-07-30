#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> a(n, 0), b(n, 0);
        int as=0, bs=0;
        for(int i = n-1; i >= 0; i--){
            a[i] = as;
            if(s[i] == 'a'){
                as++;
            }
        }
        
        for(int i=0; i < n; i++){
            b[i]=bs;
            if(s[i] == 'b'){
                bs++;
            }
        }

        int ans = n;

        for(int i=0; i<n; i++){
            ans = min(ans, a[i]+b[i]);
        }
        return  ans;
    }
};
