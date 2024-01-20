impl Solution {
    pub fn sum_subarray_mins(mut arr: Vec<i32>) -> i32 {
        let size = arr.len();
        let mut left = vec![0_usize; size];
        let mut right = vec![size-1; size];

        let mut st = Vec::new();
        
        for (curindex, &curelem) in arr.iter().enumerate(){
            while let Some(elem) = st.last() {
                if arr[*elem] >= curelem{
                    st.pop();
                }
                else {
                    break;
                }
            }

            left[curindex] = match st.last() {
                Some(&x) => x+1_usize,
                None => 0_usize
            };

            st.push(curindex);
        }

        st.clear();

        for (curindex, &curelem) in arr.iter().enumerate().rev(){
            while let Some(elem) = st.last() {
                if arr[*elem] > curelem{
                    st.pop();
                }
                else{
                    break;
                }
            }

            right[curindex] = match st.last() {
                Some(&x) => x-1_usize,
                None => size-1_usize
            };

            st.push(curindex);
        }
        let mut cur = 0_usize;
        let mut sum = 0;
        let m = 1e9 as i64 +7;
        for (l,r) in left.into_iter().zip(right.into_iter()){
            let mut cursum = (cur - l+1) as i64 * (r - cur+1) as i64;
            cursum%=m;
            sum+=(cursum*arr[cur] as i64);
            sum%=m;
            cur+=1;
        }

        sum as i32
    }
}
