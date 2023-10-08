impl Solution {
    pub fn max_dot_product(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let (s1,s2) = (nums1.len(), nums2.len());

        let mut table = vec![vec![0;s2];s1];

        for (i, num1) in nums1.iter().enumerate(){
            for (j, num2) in nums2.iter().enumerate(){
                table[i][j] = num1*num2;
            }
        }

        for i in 1..s1{
            table[i][0] = table[i-1][0].max(table[i][0]);
        }
        for i in 1..s2{
            table[0][i] = table[0][i-1].max(table[0][i]);
        }

        for i in 1..s1{
            for j in 1..s2{
                table[i][j] = table[i-1][j].max(table[i][j-1]).max(table[i][j]+table[i-1][j-1]).max(table[i-1][j-1]).max(table[i][j]);
            }
        }

        table[s1-1][s2-1]

    }
}
