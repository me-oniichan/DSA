#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

int countFactors(int n){
    int count = 0;
    for (int i=1; i<=sqrt(n); i++)
	{
		if (n%i == 0)
		{
            if (n/i == i) count++;
            else count+=2;
		}
	}
    return count;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        cout<<countFactors(abs(b-a))<<endl;
    }
return 0;
}