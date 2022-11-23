#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int start = 0, end = matrix.size() -1;
        int posx, posy;
        while(start < end){
            posy = start;
            for(int i = start; i < end; i++){
                posx = i;
                int elem = matrix[posy][posx];

                //move from top to right
                posy = posx;
                posx = end;
                swap(elem, matrix[posy][posx]);

                //move from right to bottom
                posx = end - posy+start;
                posy = end;
                swap(elem, matrix[posy][posx]);

                //move from bottom to left
                posy = posx;
                posx = start;
                swap(elem, matrix[posy][posx]);

                //move from left to top
                posx = end - posy + start;
                posy = start;
                swap(elem, matrix[posy][posx]);
            }
            start++; end--;
        }
    }
};

int main(){
    
return 0;
}