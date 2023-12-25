#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        
        int negs = 0, zero = 0;
        for (auto i : arr){
            if (i < 0) negs++;
            else if (i==0){
                zero=1;
                break;
            }
        }

        if (zero > 0 || negs%2==1){
            cout<<0<<"\n";
        }
        else {
            cout<<1<<"\n";
            cout<<1<<" "<<0<<"\n";
        }

    }
}
