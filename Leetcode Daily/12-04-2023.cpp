#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    string simplifyPath(string path) {
        deque<string> st;
        string str;
        path.push_back('/');
        for(char c : path){
            if(c=='/'){
                if(str.empty()||str=="."){str.clear(); continue;}
                else if(str == "..") if(!st.empty()) st.pop_back();
                else st.push_back(str);
                str.clear();
            }else{
                str.push_back(c);
            }
        }
        path.clear();
        while(!st.empty()){
            path.push_back('/');
            path+=st.front();
            st.pop_front();
        }
        if(path.empty()) path.push_back('/');
        return path;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}