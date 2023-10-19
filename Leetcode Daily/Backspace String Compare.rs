use std::cmp::Ordering;

impl Solution {
    pub fn backspace_compare(s: String, t: String) -> bool {
        
        let mut st= Vec::new();
        let mut st2 = Vec::new();
        for c in s.chars(){
            if c=='#'{
                st.pop();
            }
            else {
                st.push(c);
            }
        }
        
        for c in t.chars(){
            if c=='#'{
                st2.pop();
            }
            else {
                st2.push(c);
            }
        }

        st.cmp(&st2) == Ordering::Equal
        
    }
}
