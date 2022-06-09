//Problem statement: https://www.codechef.com/problems/SUMTRIAN

#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
        cin>>t;
        while(t--){
          int n;
          cin>>n;
          long long sum[n+1] = {0}, prev[n+1] = {0};
          cin>>sum[1];

          for (int i = 1; i < n; i++)
          {
            for (int k = 0; k < n+1; k++){
              prev[k] = sum[k];
            }
            int elem;
            for (int j = 0; j < i+1; j++)
            {
              cin>>elem;
              sum[j+1] = elem + max(prev[j], prev[j+1]);
            }
          }

          cout<<*max_element(sum, sum+n+1)<<endl;
        }
return 0;
}