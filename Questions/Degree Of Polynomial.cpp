//Problem Statement: https://www.codechef.com/MAY222D/problems/DPOLY/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n], x= n;
	    for (int i = 0; i < n; i++){
	        cin>>arr[i];
	    }
	    while(n--){
	        if (arr[n] == 0) x--;
	        else break;
	    }
	    cout<<x-1<<endl;
	}
	return 0;
}
