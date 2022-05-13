//Problem Statement : https://www.codechef.com/problems/SC31
#include <bits/stdc++.h>
using namespace std;

int count(int num){
    int ans = 0;
    while(num){
        num&=(num-1);
        ans++;
    }
    return ans;
}

int main() {
	int t, n;
	cin>>t;
	while(t--){
	    cin>>n;
	    char bin[10]; cin>>bin;
	    int num = stoi(bin, 0 , 2);
	    for ( int i = 1; i < n; i++){
	        cin>>bin;
	        num  = num^stoi(bin, 0 ,2);
	    }
	    std::cout << count(num) << std::endl;
	}
	return 0;
}
