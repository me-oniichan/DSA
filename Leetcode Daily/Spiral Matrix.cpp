#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int x = 0, y=0, height = matrix.size()-1, width = matrix[0].size()-1;
        int i=0,j=0;
        int direc = 0;
        vector<int> ans;

        while(y<=height && x<=width){
            ans.push_back(matrix[j][i]);
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
        return ans;
    }
};

int main(){
    int w,h;
    cin>>w>>h;
    vector<vector<int>> mat(h, vector<int>(w));
    for(int i=0; i < h; i++){
        for(int j=0; j < w; j++){
            cin>>mat[i][j];
        }
    }

    Solution sol;
    for(int i : sol.spiralOrder(mat)){
        cout<<i<<' ';
    };

    
}