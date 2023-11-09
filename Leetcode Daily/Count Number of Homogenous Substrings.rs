impl Solution {
    pub fn count_homogenous(s: String) -> i32 {
        let mut prev = '-';
        let mut ans = 0;
        let mut glen = 0;
        let m = 1e9 as i32 + 7;
        for c in s.chars(){
            if c == prev{
                glen+=1;
                ans+=glen;
                ans%=m;
            }
            else {
                ans+=1;
                ans%=m;
                glen = 1;
                prev = c;
            }

        }

        ans
    }
}
