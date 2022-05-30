//Problem Statement: https://www.codechef.com/MAY222D/problems/MAKEZERO/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n, elem, bits = 0;
	    cin>>n;
	    while(n--){
	        cin>>elem;
	        bits|=elem;
	    }
	    
	    //count num of bits in elem
	    int count = 0;
	    while(bits){
	        bits&=(bits-1);
	        count++;
	    }
	    cout<<count<<endl;
	}
	return 0;
}
