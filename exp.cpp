#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    string s;
	    cin>>s;
	    int one = count(s.begin(), s.end(), '1');
	    int zero = count(s.begin(), s.end(), '0');
	    if (n%2 == 0) std::cout << "no" << std::endl;
	    else if(one == zero) cout<<"yes"<<endl<<1<<" "<<n<<endl;
	    else{
            int diff;
	        if(zero > one){
                diff = zero - one;
                string substr = string("0");
                cout<<substr<<endl;
            }
	    }
	}
	return 0;
}
