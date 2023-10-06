impl Solution {
    pub fn integer_break(n: i32) -> i32 {
        if n <= 3{
            return n-1;
        }
        if (n%3==0){
            return 3_i32.pow((n/3) as u32);
        }
        else if n%3==1{
            return 3_i32.pow((n/3)as u32 -1)*4;
        }
        return 3_i32.pow((n/3) as u32)*2;
    }
}

