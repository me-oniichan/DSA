//Problem Statement: https://www.codechef.com/JUNE222D/problems/STRNG

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 1; i < n; i++)
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n], left[n], right[n];
        cin>>arr[0]; left[0] = arr[0];
        fii{
            cin>>arr[i];
            left[i] = __gcd(left[i-1], arr[i]);
        }
        right[n-1] = arr[n-1];
        fii{
            right[n-i-1] = __gcd(right[n-i], arr[n-1-i]);
        }
        int strg = 0;
        for (int i = 0; i  < n; i++){
            if (i == 0){
                if (right[i+1] != 1) strg++;
            }
            else if (i==n-1){
                if (left[n-2] !=1) strg++;
            }
            else{
                if (__gcd(left[i-1], right[i+1]) != 1) strg++;
            }
        }
        cout<<strg<<endl;
    }
return 0;
}