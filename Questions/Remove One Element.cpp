//Problem Statement : https://www.codechef.com/problems/REMONE?tab=statement

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n, elem, max1[2] = {0}, min1 = INT_MAX, max2 = 0, min2 = INT_MAX;
        cin>>n;
        fii{
            cin>>elem;
            max1[1] = max1[0];
            max1[0] = max(max1[0], elem);
            min1 = min(min1, elem);
        }
        
        for(int i =0; i < n-1; i++){
            cin>>elem;
            max2 = max(max2, elem);
            min2 = min(min2, elem);
        }

        if (n==2){
            if(max2  < max1[0]) cout<<max2-max1[1]<<endl;
            else cout<<max2-max1[0]<<endl;  
        } 
        else if(max2-max1[0] == min2 - min1) cout<<max2-max1[0]<<endl;
        else if (max2-max1[1] == min2 - min1) cout<<min2 - min1<<endl;
        else cout<<max2-max1[0]<<endl;
    }

return 0;
}