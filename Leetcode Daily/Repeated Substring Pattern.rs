impl Solution {
    pub fn repeated_substring_pattern(s: String) -> bool {
        let ss= (s.clone()+&s)[1..s.len()*2 -1];
        ss.contains(&s)
    }
}
