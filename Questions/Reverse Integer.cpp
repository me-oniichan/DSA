//Problem Statement : https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/880/
//Solved assuming system cannot process 64 bit numbers

#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int rev = 0, remainder = 0;
        while(x){
            remainder = x%10;
            rev = rev*10+remainder;
            x/=10;
            if (rev > 214748364 and x) return 0;
            else if (rev == 214748364 and x >7) return 0;
            else if(rev < -214748364 and x) return 0;
            else if(rev == -214748364 and x < -8) return 0;
        }
        return rev;
    }
}; 
 
int main(){
    int x;
    cin>>x;
    cout<<Solution().reverse(x)<<endl;
 
return 0;
}