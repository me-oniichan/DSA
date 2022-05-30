//Peoblem Statement: https://www.hackerrank.com/challenges/jesse-and-cookies

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    int moves = 0, elem, store = -1;
    priority_queue<int,vector<int>,greater<int>> cookies;
    for (int i  = 0; i < n; i++){
        cin>>elem;
        if (elem < k) cookies.push(elem);
        else store = elem;
    }
    
    while (cookies.size()) {
        if (cookies.size() == 1){
            if (store != -1){
                moves++;
                break;
            }
            else{
                moves = -1;
                break;
            }
        }
        else if(cookies.size() == 0) break;
        int cookie1 = cookies.top();
        cookies.pop();
        int cookie2 = cookies.top();
        cookies.pop();
        elem = cookie1 + 2*cookie2;
        if (elem < k) cookies.push(elem);
        else store = elem;
        moves++;
    }
    cout<<moves<<endl;
    
    return 0;
}
