//Problem Statement: https://www.codechef.com/submit/AVG
#include <iostream>
using namespace std;

int main() {
	int t, n, k, v;
	cin>>t;
	while(t--){
	    cin>>n>>k>>v;
	    int sum = 0;
	    for (int i = 0; i < n; i++){
	        int val;
	        cin>>val;
	        sum+=val;
	    }
	    int ans = v*(n+k) - sum;
	    if (ans%k == 0 && ans > 0) std::cout << ans/k << std::endl;
	    else cout<<-1<<endl;
	}
	return 0;
}
