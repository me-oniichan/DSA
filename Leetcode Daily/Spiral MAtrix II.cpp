#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int x = 0, y=0, height = matrix.size()-1, width = matrix[0].size()-1;
        int i=0,j=0;
        int direc = 0;
        int v=1;
        while(y<=height && x<=width){
            matrix[j][i] = v++;
            if(direc==0){
                if (i==width){
                    y++;
                    direc=1;
                }else i++;
            }
            if(direc==1){
                if(j==height){
                    width--;
                    direc=2;
                }else j++;
            }
            if(direc ==2){
                if(i==x){
                    height--;
                    direc=3;
                }else i--;
            }
            if(direc==3){
                if(j==y){
                    x++;
                    i=x;
                    direc=0;
                }else j--;
            }
        }
        return matrix;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    
return 0;
}