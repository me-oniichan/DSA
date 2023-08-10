impl Solution {
    pub fn longest_subsequence(arr: Vec<i32>, difference: i32) -> i32 {
        use std::collections::HashMap;

        let mut map = HashMap::new();
        let mut ans : i32 = 1;
        for &i in &arr{
            let req = i-difference;
            match map.get(&req) {
                Some(len) => {
                    ans = std::cmp::max(ans, len+1);
                    map.insert(i, len+1);
                },
                None => {map.insert(i, 1);},
            }
        }

        ans

    }
}
