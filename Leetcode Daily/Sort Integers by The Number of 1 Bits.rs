impl Solution {
    pub fn sort_by_bits(arr: Vec<i32>) -> Vec<i32> {
        let mut bits = vec![(0_u32,0); arr.len()];

        for (i, j) in arr.into_iter().zip(bits.iter_mut()){
            *j = (i.count_ones(), i);
        }

        bits.sort();
        bits.into_iter().map(|x| x.1).collect()
    }
}
