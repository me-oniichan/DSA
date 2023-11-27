#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

const int m = 1000000007;
class Solution {
public:
    int knightDialer(int n) {
      vector<int> prev(10,1);
      vector<int> cur(10,0);
      
      for(int i = 1; i < n; i++){
        for(int j=0; j < 10; j++){
          switch (j) {
            case 0:
              cur[0] = (prev[4]+prev[6])%m;
              break;
            case 1:
              cur[1] = (prev[6]+prev[8])%m;
              break;
            case 2:
              cur[2] = (prev[7]+prev[9])%m;
              break;  
            case 3:
              cur[3] = (prev[4]+prev[8])%m;
              break;
            case 4:
              cur[4] = ((prev[0]+prev[3])%m+prev[9])%m;
              break;
            case 6:
              cur[6] = ((prev[0]+prev[1])%m+prev[7])%m;
              break;
            case 7:
              cur[7] = (prev[6]+prev[2])%m;
              break;
            case 8:
              cur[8] = (prev[1]+prev[3])%m;
              break;
            case 9:
              cur[9] = (prev[2]+prev[4])%m;
              break;
          }
        }
        prev = cur;
      }

      int ans = 0;
      for (int j=0; j < 10; j++){
        ans+=prev[j];
        ans%=m;
      }
      return ans;
    }
};
