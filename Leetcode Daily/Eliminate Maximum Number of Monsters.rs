impl Solution {
    pub fn eliminate_maximum(mut dist: Vec<i32>, speed: Vec<i32>) -> i32 {
        let mut time = Vec::new();
        for (d,s) in dist.iter().zip(speed.iter()){
            time.push(d as f64/s as f64);
        }

        time.sort_by(|a,b| a.partial_cmp(b).unwrap());
        let mut curtime=0 as f64;
        let mut ans =0;
        for t in time{
            if t > curtime{
                ans+=1;
                curtime= curtime.min(t) +1.0;
            }
            else {
                return ans;
            }
        }

        return ans;

    }
}
