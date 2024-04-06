impl Solution {
    pub fn min_remove_to_make_valid(s: String) -> String {
        let mut stack = Vec::new();
        let mut s = s.chars().collect::<Vec<_>>();
        for i in 0..s.len() {
            if s[i] == '(' {
                stack.push(i);
            } else if s[i] == ')' {
                if stack.is_empty() {
                    s[i] = ' ';
                } else {
                    stack.pop();
                }
            }
        }
        for i in stack {
            s[i] = ' ';
        }
        s.into_iter().filter(|&c| c != ' ').collect()
    }
}
