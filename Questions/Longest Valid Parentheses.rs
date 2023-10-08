impl Solution {
    pub fn longest_valid_parentheses(s: String) -> i32 {
        let mut st = Vec::new();
        let mut ans = 0;
        let mut count = 0;
        let mut s: Vec<char> = s.chars().collect();
        
        for i in 0..s.len(){
            if s[i]=='('{
                st.push(i)
            }
            
            else {
                match st.last_mut() {
                    Some(&x) => {
                        if s[x] == '('{
                            st.pop();
                            s[x] = ' ';
                            s[i] = ' ';
                        }
                    },
                    None => {
                        st.push(i);
                    }
                }
            }

        }

        for i in s.iter(){
            if *i == ' '{
                count+=1;
            }
            else {
                ans = ans.max(count);
                count=0;
            }
        }
        ans = ans.max(count);
        ans
    }
}
