//Problem Statement: https://www.codechef.com/problems/ABOVEAVG
#include <iostream>
using namespace std;

int main() {
	int t, n, a, m;
	cin>>t;
	while(t--){
	    cin>>n>>m>>a;
	    if (m == a) std::cout << 0 << std::endl;
	    else{
	        cout<<(a*n)/(a+1)<<endl;
	    }
	}
	return 0;
}
