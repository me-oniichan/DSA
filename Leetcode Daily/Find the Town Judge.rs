use std::collections::HashSet;

impl Solution {
    pub fn find_judge(n: i32, trust: Vec<Vec<i32>>) -> i32 {
        let mut trusters = HashSet::new();
        let mut trusted = vec![0; n as usize];
        for t in trust {
            trusters.insert(t[0]);
            trusted[t[1] as usize - 1] += 1;
        }
        for i in 0..n as usize {
            if trusted[i] == n - 1 && !trusters.contains(&(i as i32 + 1)) {
                return i as i32 + 1;
            }
        }
        -1
    }
}
