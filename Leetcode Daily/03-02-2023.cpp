#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    string convert(string s, int numRows) {
        int r=0, size = s.size();
        string str;
        numRows--;
        for(int i=0; i <= numRows; i++){
            r=0;
            while(true){
                if(r*numRows-i > 0 && r*numRows-i < size && i>0 && i < numRows) str.push_back(s[r*numRows-i]);
                if(r*numRows+i >= size) break;
                str.push_back(s[r*numRows+i]);
                r+=2;
            }
        }
        return str;
    }
};