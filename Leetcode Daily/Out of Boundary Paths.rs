use std::collections::VecDeque;

impl Solution {
    pub fn find_paths(m: i32, n: i32, max_move: i32, start_row: i32, start_column: i32) -> i32 {
        let directions = vec![(0,1), (0,-1), (1,0), (-1,0)];
        let mut grid = vec![vec![0;n as usize]; m as usize];
        let mut ans = 0;
        grid[start_row as usize][start_column as usize] = 1;
        let mo = 1e9 as i32 +7;
        let mut q = VecDeque::new();
        q.push_back((start_row, start_column));
        
        for i in 0..max_move{
            let mut tempq = VecDeque::new();
            for (row, col) in q{
                for &(r,c) in directions.iter(){
                    let next_row = row+r;
                    let next_col = col+c;
                    
                    if (next_row<m && next_row>=0 && next_col<n && next_col>=0){
                        grid[next_row as usize][next_col as usize]+= grid[row as usize][col as usize];
                        grid[next_row as usize][next_col as usize]%=mo;

                        tempq.push_back((next_row, next_col));
                    } else {
                        ans+=grid[row as usize][col as usize];
                        ans%=mo;
                    }
                }
            }
            q = tempq;
        }

        ans
    }
}

fn main(){
    let ans = Solution::find_paths(2,2,2,0,0);
    println!("{ans}");
}
