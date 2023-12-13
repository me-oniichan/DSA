impl Solution {
    pub fn num_special(mat: Vec<Vec<i32>>) -> i32 {
        let mut cols = vec![0; mat.len()];
        let mut rows = vec![0; mat[0_usize].len()];

        mat.iter().enumerate().for_each(|(i, r)|{

            r.iter().enumerate().for_each(|(j, &n)|{
                if n==1{
                    cols[i]+=1;
                    rows[j]+=1;
                }
            }) 
        });
        
        let mut ans = 0;
        
        cols.iter().enumerate().for_each(|(i, &c)|{
            if c==1 {
                rows.iter().enumerate().for_each(|(j, &r)|{
                    if r==1 && mat[i][j]==1{
                        ans+=1;
                    }
                });
            }
        });
        ans
    }
}
