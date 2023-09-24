impl Solution {
    pub fn champagne_tower(poured: i32, query_row: i32, query_glass: i32) -> f64 {
       let query_row = query_row as usize;
        let width = query_row+1;
       let mut prev = vec![0 as f64;width];
       prev[0] = poured as f64;
       let mut cur = vec![0 as f64;width];

        for i in 1..query_row+1{
            for j in 0..i+1{
                let left: f64 = match j {
                    0 => 0.0,
                    x => 0_f64.max(prev[x-1]-1.0)/2.0, 
                };
                
                let right: f64  = 0_f64.max(prev[j]-1.0)/2.0;
                cur[j] = left+right;
            }

            prev = cur.clone();
            for elem in cur.iter_mut(){
                *elem = 0.0;
            }
        }

        match prev[query_glass as usize]{
            x if x>1.0 => 1.0,
            x => x,
        }
    }
}

