#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    string predictPartyVictory(string senate) {
        int r=0,d=0;
        list<char> li;
        for(char c : senate){
            li.push_back(c);
            if(c=='R') r++;
            else d++;
        }
        int rd=0,dd=0;
        auto iter = li.begin();
        while(r>0 && d>0){
            if(iter==li.end()) iter = li.begin();
            if(*iter == 'R'){
                if(rd>0){
                    li.erase(iter++);
                    r--;
                    rd--;
                    continue;
                }
                else dd++;
            }else{
                if(dd>0){
                    li.erase(iter++);
                    d--;
                    dd--;
                    continue;
                }else rd++;
            }
            iter++;
        }
        if(r>d) return "Radiant";
        else return "Dire";
    }
}; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}