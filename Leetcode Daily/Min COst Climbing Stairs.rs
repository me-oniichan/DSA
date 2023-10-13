impl Solution {
    pub fn min_cost_climbing_stairs(cost: Vec<i32>) -> i32 {
        let mut prev1=0;
        let mut prev2=0;

        for &i in cost.iter(){
            let c = i + prev1.min(prev2);
            prev2 = prev1;
            prev1 = c;
        }

        prev1.min(prev2)
    }
}
