//Problem Statement : https://www.codechef.com/problems/MXMODSUM

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int m, n;
	    cin>>n>>m;
	    int arr[n];
	    for(int i  = 0; i< n; i++){
	        cin>>arr[i];
	    }
        sort(arr, arr+n);
        int max=0, res;
        for (int i = 0; i < n; i++){
            res = arr[i] + arr[n-1] + (arr[i] - arr[n-1]%m + m)%m;
            if (res > max) max = res;
        }
        std::cout << max << std::endl;
	}
	return 0;
}
