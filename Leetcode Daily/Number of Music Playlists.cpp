#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

const int m = 1000000007;

class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
	   vector<vector<long>> dp(goal+1, vector<long>(n+1));
	   dp[0][0]=1;

	   for(int i=0; i <= goal; i++){
		  for(int j=1; j <= min(i,n); j++){
			 dp[i][j] = dp[i-1][j-1]*(n-j+1)%m;

			 if(j>k){
				dp[i][j] = (dp[i][j]+dp[i-1][j]*(j-k))%m;
			 }
		  }
	   }
	   return dp[goal][n];
    }
};
