//Problem Statement: https://www.codechef.com/submit/PALINPAIN

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        if ((x&y&1) || x == 1 || y == 1) cout<<-1<<endl;
        else{
            string s;
            int mid;
            if (x&1){
                s = string (x+y, 'a');
                mid = y/2;
                for(int i = 0; i < mid; i++){
                    s[i] = s[x+y-1-i] = 'b';
                }
            }
            else{
                s = string (x+y, 'b');
                mid = x/2;
                for(int i = 0; i < x/2; i++){
                    s[i] = s[x+y-1-i] = 'a';
                }
            }

            cout<<s<<endl;
            char temp = s[mid];
            s[mid] = s[(x+y) -1 - mid] = s[mid-1];
            s[mid-1] = s[(x+y) - mid] = temp;
            cout<<s<<endl;
        }
    }
return 0;
}