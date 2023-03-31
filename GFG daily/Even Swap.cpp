#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution
{
    public:
        vector <int> lexicographicallyLargest(vector <int> &a,int n)
        {
            int start=0,i=1;
            for(; i < n; i++){
                if(a[i]%2 != a[i-1]%2){
                    sort(a.begin()+start, a.begin()+i, greater<int>());
                    start=i;
                }
            }
            sort(a.begin()+start, a.begin()+i, greater<int>());
            return a;
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}