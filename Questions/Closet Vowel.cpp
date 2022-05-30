//"Problem Statement : https://www.codechef.com/START39D/problems/CLOSEVOWEL
#include <bits/stdc++.h>
#define m 1000000007
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    long long count = 1;
	    cin>>n;
	    string s; cin>>s;
	    for (int i = 0; i < n; i++){
	        if (s.at(i) == 'c' || s.at(i) == 'g' ||s.at(i) == 'l' ||s.at(i) == 'r') count= count%m *2;
	    }
	    cout<<count%m<<endl;
	}
	return 0;
}
