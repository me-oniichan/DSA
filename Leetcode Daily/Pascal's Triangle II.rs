impl Solution {
    pub fn get_row(row_index: i32) -> Vec<i32> {
        let mut prev = vec![1];
        let mut cur = vec![1,1];
        
        for i in 0..row_index{
            for j in 1..prev.len(){
                cur[j] = prev[j-1]+prev[j];
            }
            
            prev = cur;
            cur = vec![1;prev.len()+1];
        }
        prev
    }
}
