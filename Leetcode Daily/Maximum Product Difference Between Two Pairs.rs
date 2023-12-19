impl Solution {
    pub fn max_product_difference(nums: Vec<i32>) -> i32 {
        let (mut big1, mut big2, mut small1, mut small2) = (0, 0, i32::MAX, i32::MAX);
        
        for ele in nums {
            if ele >= big1{
                big2 = big1;
                big1 = ele;
            }
            else if ele > big2{
                big2 = ele;
            }

            if ele <= small1{
                small2 = small1;
                small1 = ele;
            }
            else if ele < small2 {
                small2 = ele;
            }
        }

        big1*big2 - small1*small2
    }
}
