impl Solution {
    pub fn least_interval(tasks: Vec<char>, n: i32) -> i32 {
        let mut v = vec![0; 26];
        for &x in tasks.iter() {
            v[x as usize - 'A' as usize] += 1;
        }
        v.sort_unstable();
        let max = v[25] - 1;
        let mut idles = n * max;
        for i in (0..25).rev() {
            idles -= max.min(v[i]);
        }
        tasks.len() as i32 + idles.max(0)
    }
}
