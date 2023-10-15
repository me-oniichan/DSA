impl Solution {
    pub fn num_ways(steps: i32, arr_len: i32) -> i32 {
        let size = arr_len.min(steps/2 +1) as usize;
        let m = 1e9 as i32+7;
        let mut prev = vec![0; size];
        let mut curr = vec![0; size];
        prev[0] = 1;

        for i in 0..steps{
            for j in 0..size{
                curr[j]= match j {
                    0 => 0,
                    x => prev[x-1],
                };
                curr[j]%=m;

                curr[j] += prev[j];
                curr[j]%=m;
                curr[j] += match j+1==size {
                    true => 0,
                    false => prev[j+1],
                };
                curr[j]%=m;

            }

            prev = curr;
            curr = vec![0; size];
        }

        prev[0]
    }
}

