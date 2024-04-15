impl Solution {
    pub fn maximal_rectangle(matrix: Vec<Vec<char>>) -> i32 {
        let rows = matrix.len();
        let cols = matrix[0].len();

        let mut dp_rows = vec![vec![0; cols+1]; rows+1];
        let mut dp_cols = vec![vec![0; cols+1]; rows+1];
        
        let mut ans = 0;

        for r in 0..rows{
            for c in 0..cols{
                if matrix[r][c] == '0'{
                    dp_rows[r+1][c+1] = 0;
                    dp_cols[r+1][c+1] = 0;
                }
                else {
                    dp_cols[r+1][c+1] = dp_cols[r+1][c]+1;
                    dp_rows[r+1][c+1] = dp_rows[r][c+1]+1;

                    let mut min_col = dp_cols[r+1][c+1];
                    let mut count_rows = 1;
                    for ur in (1..r+2).rev(){
                        if (dp_cols[ur][c+1] == 0){
                            break;
                        }

                        min_col = min_col.min(dp_cols[ur][c+1]);
                        let area = min_col*count_rows;
                        ans = ans.max(area);
                        count_rows+=1;
                    }
                }
            }
        }

        ans as i32
    }
}
