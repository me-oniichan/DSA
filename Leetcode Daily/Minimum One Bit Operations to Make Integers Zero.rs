impl Solution {
    pub fn minimum_one_bit_operations(n: i32) -> i32 {
        (0..32).map(|i| n >> i)
            .take_while(|&x| x != 0)
            .fold(0, |acc, x| acc ^ x)
    }
}
