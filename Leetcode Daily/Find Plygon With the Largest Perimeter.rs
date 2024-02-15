impl Solution {
    pub fn largest_perimeter(mut nums: Vec<i32>) -> i64 {
        nums.sort_unstable();
        let mut perimeter = nums.iter().fold(0_i64, |mut acc, &elem|{acc += (elem as i64); acc});
        for i in nums.into_iter().skip(2).rev(){
            let val = i as i64;
            if perimeter - val > val{
                return perimeter;
            }
            else {
                perimeter -= val;
            }
        }

        -1 as i64
    }
}
