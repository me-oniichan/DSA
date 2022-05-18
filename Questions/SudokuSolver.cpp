#include<iostream>
#include<vector>


using namespace std;

bool check(int grid[9][9], int row, int col, int val){
    for(int i = 0; i<9;i++){
        if (grid[row][i] == val) return false;
        if (grid[i][col] == val) return false;
    }
    for (int i = 0;i< 3;i++){
        if (row < 3 && col < 3){
            if (grid[i][0] == val || grid[i][1] == val || grid[i][2] == val) return false;
        }
        else if (row < 6 && col < 3){
            if (grid[i+3][0] == val || grid[i+3][1] == val || grid[i+3][2] == val) return false;
        }
        else if (row < 9 && col < 3){
            if (grid[i+6][0] == val || grid[i+6][1] == val || grid[i+6][2] == val) return false;
        }
        else if (row < 3 && col < 6){
            if (grid[i][3] == val || grid[i][4] == val || grid[i][5] == val) return false;
        }
        else if (row < 3 && col < 9){
            if (grid[i][6] == val || grid[i][7] == val || grid[i][8] == val) return false;
        }
        else if (row < 6 && col < 6){
            if (grid[i+3][3] == val || grid[i+3][4] == val || grid[i+3][5] == val) return false;
        }
        else if (row < 6 && col < 9){
            if (grid[i+3][6] == val || grid[i+3][7] == val || grid[i+3][8] == val) return false;
        }
        else if (row < 9 && col < 6){
            if (grid[i+6][3] == val || grid[i+6][4] == val || grid[i+6][5] == val) return false;
        }
        else if (row < 9 && col < 9){
            if (grid[i+6][6] == val || grid[i+6][7] == val || grid[i+6][8] == val) return false;
        }
    }
    
return true;
}

bool solve(int grid[9][9], int row, int col){
    if (row == 9 && col == 9) return true;
    else if (row == 9) {
        row = 0; col++;
    }
    //if cell is filled by default
    if (grid[row][col] > 0){
        return solve(grid, row+1, col);
    }
    
    for (int i = 1; i <= 9; i++){
        //if number is not present in row column and nonet
        if (check(grid, row, col, i)){
            grid[row][col] = i;
            if (solve(grid, row+1, col)){
                return true;
            }
            else{
                grid[row][col] = 0;
            }
        }
    }
    //if no number fits then return false to fallback
    return false;
}

void sudoku_solve(int grid[9][9]) {
    solve(grid, 0, 0);
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            cout<<grid[i][j]<<' ';
        }
        cout<<endl;
    }
}

int main() {
    int n, board[9][9];
    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<9;j++) {
            for(int k=0;k<9;k++) {
                board[j][k] = 0;
                cin >> board[j][k];
            }
        }
        sudoku_solve(board);
    }
    return 0;
}
