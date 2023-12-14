impl Solution {
    pub fn ones_minus_zeros(mut grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut rows = vec![0; grid.len()];
        let mut cols = vec![0; grid[0].len()];

        grid.iter().enumerate().for_each(|(i, r)|{
            r.iter().enumerate().for_each(|(j, &c)|{
                if c==0{
                    rows[i]-=1;
                    cols[j]-=1;
                }
                else {
                    rows[i]+=1;
                    cols[j]+=1;
                }
            });
        });

        for (i, r) in rows.iter().enumerate(){
            for (j, c) in cols.iter().enumerate(){
                grid[i][j] = r+c;
            }
        }

        grid
    }
}
