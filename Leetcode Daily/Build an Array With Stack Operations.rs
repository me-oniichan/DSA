impl Solution {
    pub fn build_array(target: Vec<i32>, n: i32) -> Vec<String> {
        let mut ans = Vec::new();
        
        let mut prev = 0;
        target.iter().for_each(|&n| {
            for i in prev..n-1{
                ans.push("Push".to_string());
                ans.push("Pop".to_string());
            }
            ans.push("Push".to_string());
            prev = n;
        });

        ans
    }
}

