#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        float mid = (float)matrix.size()/2.0;
        int start = 0, end = matrix.size()-1;
        int elem, posx=0, posy=0;
        int initx=0, inity=0;
        elem = matrix[posy][posx];

        while(start < end){
            if(posy == start){
                posy = posx;
                posx = end;
                swap(elem, matrix[posy][posx]);
            }
            else if(posx == end){
                posx = matrix.size() - posy-1;
                posy = end;
                swap(elem, matrix[posy][posx]);
            }
            else if(posy == end){
                posy = matrix.size()-1-posx;
                posx = start;
                swap(elem, matrix[posy][posx]);
            }
            else if(posx==start){
                posx = posy;
                posy = start;
                swap(elem, matrix[posy][posx]);
            }
            if(posx==initx && posy==inity){
                posx = initx = initx == end? initx: initx+1;
            }
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}