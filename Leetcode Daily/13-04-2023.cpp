#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0,j=0;
        stack<int> s;
        for(int i : pushed){
            s.push(i);
            while(!s.empty()){
                if(j < popped.size() && s.top() == popped[j]){
                    s.pop(); j++;
                }else break;
            }
        }
        if(j==popped.size()) return true;
        else return false;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}