#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v(n);
        for(int i=0;i<n;i++) v[i] = i+1;
        int i = 0;
        while(v.size() > 1){
            i = (i+k-1)%v.size();
            v.erase(v.begin()+i);
        }
        return v[0];
    }
};
