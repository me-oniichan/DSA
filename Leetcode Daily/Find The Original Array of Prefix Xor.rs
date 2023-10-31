use std::ops::BitXor;

impl Solution {
    pub fn find_array(mut pref: Vec<i32>) -> Vec<i32> {
        let mut prev = 0;

        for i in pref.iter_mut(){
            let cur = i.bitxor(prev);
            *i = cur;
            prev = prev^cur;
        }

        pref
    }
}
