#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int passThePillow(int n, int time){
        int k = time % (n - 1);
        int direct = time/(n-1) % 2;
        if(direct == 0){
            return k + 1;
        }else{
            return n - k;
        }
    }
};
