
impl Solution {
    pub fn min_cost(mut colors: String, mut needed_time: Vec<i32>) -> i32 {
        let mut curmax = 0;
        let mut prev = '_';
        let mut sum = 0;
        let mut ans  = 0;
        colors.push(' ');
        needed_time.push(0);
        for (c, &t) in colors.chars().zip(needed_time.iter()){
            if c==prev{
                curmax = curmax.max(t);
                sum+=t;
            }
            else {
                prev = c;
                ans+= sum - curmax;
                curmax = t;
                sum = t;
            }
        }
        ans
    }
}

