//Problem Statement: https://www.codechef.com/submit/INFERNO
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n, x;
	cin>>t;
	while(t--){
	    cin>>n>>x;
	    int arr[n], t2 = 0;
	    for(int i = 0; i < n; i++){
	        cin>>arr[i];
	        t2+=ceil(float(arr[i])/float(x));
	    }
	    
	    int t1 = *max_element(arr, arr+n);
	    std::cout << min(t1, t2) << std::endl;
	}
	return 0;
}
