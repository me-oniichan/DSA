impl Solution {
    pub fn find_longest_chain(pairs: Vec<Vec<i32>>) -> i32 {
        let mut pairs = pairs;
        pairs.sort_by(|a,b| a[1].cmp(&b[1]));
        let size = pairs.len();
        let mut count=0;
        let mut prev = i32::MIN;

        for i in pairs{
            if i[0] > prev{
                count+=1;
                prev = i[1];
            }
        }
        return count;
    }
}
