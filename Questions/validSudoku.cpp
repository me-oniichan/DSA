#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

bool validbox(vector<vector<char>> board, int row, int col){
    unordered_set<char> s;
    for(int i= 0; i < 3; i++){
        for(int j=0; j<3; j++){
            if(board[i+row][j+col] == '.') continue;
            else if(s.count(board[i+row][j+col]) == 0) s.insert(board[i+row][j+col]);
            else return false;
        }
    }
    return true;
}

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //check rows
        for(int i = 0; i <9; i++){
            unordered_set<char> s;
            for(char j : board[i]){
                if(j=='.') continue;
                else if(s.count(j) == 0) s.insert(j);
                else return false;
            }
        }
        //check columns
        for(int i=0; i < 9; i++){
            unordered_set<char> s;
            for(int j = 0; j < 9; j++){
                if(board[j][i]=='.') continue;
                else if(s.count(board[j][i]) == 0) s.insert(board[j][i]);
                else return false;
            }
        }
        //check boxes
        for(int i=0; i < 9; i+=3){
            for(int j=0; j < 9; j+=3){
                if(!validbox(board, i, j)) return false;
            }
        }


        return true;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}