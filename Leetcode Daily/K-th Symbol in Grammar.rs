impl Solution {
    pub fn find(n: i32, k: i32) -> i32{
        if (n==1){
            return 0;
        }

        let prev = Solution::find(n-1, (k+1)/2);
        if k%2==0{
            if prev = 0{
                return 1;
            }
            else {
                return 0;
            }
        }
        else if prev = 0{
            return 0;
        }
        else {
            return 1;
        }

    }
    pub fn kth_grammar(n: i32, k: i32) -> i32 {
        return Solution::find(n, k); 
    }
}
