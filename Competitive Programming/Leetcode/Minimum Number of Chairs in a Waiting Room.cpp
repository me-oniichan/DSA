#include <iostream>
using namespace std;

class Solution {
public:
    int minimumChairs(string s) {
        int ans = 0;
        int curcount=0;
        for(char c : s){
            if (c=='E') curcount++;
            else curcount--;

            ans = max(ans, curcount);
        }
        return ans;
    }
};
