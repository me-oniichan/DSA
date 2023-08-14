impl Solution {
    pub fn dfs(pos: Vec<Vec<i32>>, safety)
    pub fn maximum_safeness_factor(grid: Vec<Vec<i32>>) -> i32 {
        let mut prisoners = Vec::new();
        let n = grid.len();
        let mut grid = grid;
        for i in 0..n {
            for j in 0..n{
                if grid[i][j] == 1{
                    prisoners.push(vec![i,j]);
                }
            }
        }
        
        for i in 0..n{
            for j in 0..n{
                match grid[i][j] {
                    1 => {
                        grid[i][j]=0;
                    },
                    0 => {
                        grid[i][j] = i32::MAX;
                        for &v in prisoners{
                            let dist = (v[0]-i as i32).abs() + (v[1] - j as i32).abs();
                            grid[i][j] = grid[i][j].min(dist);                    
                        }
                    }
                }
            }
        }


        
    }
}
