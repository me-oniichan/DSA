#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> limits;
    int elem;
    while (cin>>elem){
        limits.push_back(elem);
    }
    int k = limits.back();
    limits.pop_back();

    sort(limits.begin(), limits.end());
    int left=0, right=limits.size()-1;
    int ans=0;

    while (left < right){
        if (limits[left]+limits[right] <= k){
            left++;
            right--;
        }
        else {
            right--;
        }
        ans+=1;
    }
    if(left==right) ans++;

    cout<<ans<<endl;

    return 0;
}
