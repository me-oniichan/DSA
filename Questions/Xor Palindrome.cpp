//PRoblem Statement: https://www.codechef.com/MAY222D/problems/XOR_PAL/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n; string s;
	    cin>>n; cin>>s;
	    float count = 0;
	    for (int i = 0; i < n/2; i++){
	        if (s[i] != s[n-1-i]) count++;
	    }
	    std::cout << ceil(count/2.0) << std::endl;
	}
	return 0;
}
