impl Solution {
    pub fn count_orders(n: i32) -> i32 {
        let m = 1e9 as i64 +7;
        let n = n as i64;
        let mut count: i64 = 1;
        for i in 2..n+1{
            count = ((count*(2*i-1))%m*i)%m;
        }
        
        count as i32
    }
}
