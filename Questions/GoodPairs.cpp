//Problem Statement: https://www.codechef.com/problems/GOODPAIRS

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t,n;
	std::cin >> t;
	while(t--){
	    cin>>n;
	    long long A[n];
	    long long elem;
	    pair<long long, long long> key;
	    map<pair<long long, long long>, long long> hmap;
	    
	    for (int i = 0; i < n; i++) {
	        cin>>A[i];
	    }
	    for (int i = 0; i < n; i++) {
	        cin>>elem;
	        key = make_pair(A[i], elem);
	        if (hmap.find(key) != hmap.end()) hmap[key]++;
	        else hmap[key] = 1;
	    }
	    
	    long long count = 0;
        for (auto i = hmap.begin();  i != hmap.end(); i++){
            key = make_pair((i->first).second, (i->first).first);
            
            if (hmap.find(key) != hmap.end()){
                if (key != i->first) {
                    count+= hmap[key] * i->second;
                    hmap[key] = 0;
                }
                else{
                    count+= hmap[key]*(hmap[key]-1)/2;
                    hmap[key] = 1;
                }
            } 
        }
        std::cout << count << std::endl;
	}
	return 0;
}
