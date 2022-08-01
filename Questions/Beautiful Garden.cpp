//Problem Statement : https://www.codechef.com/submit/BEAUTGAR

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
        string s;
        cin>>s;
        int r =0, g = 0, n = s.length();
        fii{
            if (s[i] == s[(i+1)%n]){
                s[i] == 'R'? r++ : g++; 
            }
        }

        if (r <= 1 && g <= 1 && r == g) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    } 
return 0;
}