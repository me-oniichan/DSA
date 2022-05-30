//Problem Staement: https://www.codechef.com/MAY222D/problems/SUBARRAYLEN/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n, elem;
	    cin>>n;
	    vector<pair<int, int>> arr;
	    for (int i = 0; i < n; i++){
	        cin>>elem;
	        arr.push_back({elem, i});
	    }
	    sort(arr.begin(), arr.end());
	    
	    long long count = 0;
	    pair<int, int> prev = make_pair(0 ,0);
	    
	    for (auto i = arr.begin(); i < arr.end(); i++){
	        int llimit, ulimit;
	        if ((*i).first > (*i).second ) llimit = (*i).first -1;
	        else llimit = (*i).second;
	        
	        if (prev.first == (*i).first && (*i).second - prev.second < prev.first) llimit = prev.second + (*i).first;
	        
	        ulimit = (*i).second + (*i).first -1;
	        if (ulimit > (n-1)) ulimit = n-1;
	        
	        int val = (ulimit - llimit +1);
	        if (val > 0) count+=val;
	        prev = (*i);
	    }
	    
	    std::cout << count << std::endl;
	    
	}
	return 0;
}
