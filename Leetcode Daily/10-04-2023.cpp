#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    bool check(char c, char r){
        switch (c)
        {
            case '(':
                return r==')';
            case '{':
                return r=='}';
            case '[':
                return r==']';
            default:
                return false;
        }
    }
    bool isValid(string s) {
        stack<char> st;
        for(char &i : s){
            if (i == '(' | i=='{' | i == '[') st.push(i);
            else if (check(st.top(), i)) st.pop();
            else return false;
        }
        return st.size()==1;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}