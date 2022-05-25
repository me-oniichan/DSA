//problem statement: https://www.hackerrank.com/challenges/find-the-running-median/problem

#include <bits/stdc++.h>

using namespace std;

int main(){
    cout << fixed << setprecision(1);
    int n;
    float elem;
    cin>>n;
    vector<float> vec;
    for ( int i= 0 ; i < n; i++){
        cin>>elem;
        vec.insert(lower_bound(vec.begin(), vec.end(), elem), elem);
        if ((vec.size()&1) == 0){
            cout<<(vec[vec.size()/2 -1] + vec[vec.size()/2])/2.0<<endl; 
        }
        else{
            cout<<vec[vec.size()/2]<<endl;
        }
    }
}
