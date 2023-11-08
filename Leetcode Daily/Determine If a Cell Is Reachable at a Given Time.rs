impl Solution {
    pub fn is_reachable_at_time(sx: i32, sy: i32, fx: i32, fy: i32, t: i32) -> bool {
        if sx==fx && sy == fy{
            return t!=1;
        }
        let dist = (sx - fx).abs().max((sy - fy).abs());
        dist <= t 
    }
}
