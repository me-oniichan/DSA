impl Solution {
    pub fn find_special_integer(arr: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut count = 0_usize;
        let mut prev = -1;
        let size = arr.len()/4_usize;

        for i in arr{
            if i == prev{
                count+=1;
                if count > size{
                    return i;
                }
            }
            else {
                count = 1;
                if count > size{
                    return i;
                }
                prev = i;
            }
        }
        return 0;
    }
}
