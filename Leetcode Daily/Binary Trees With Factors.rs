use std::collections::HashMap;

impl Solution {
    pub fn num_factored_binary_trees(mut arr: Vec<i32>) -> i32 {
        let size = arr.len();
        let mut dp = HashMap::new();
        let m = 1e9 as i64+7;

        arr.sort();

        for &i in arr.iter(){
            dp.insert(i, 1 as i64);
        }

        for (i , &v) in arr.iter().enumerate(){
            for j in (0..i).rev(){
                if v%arr[j] == 0{
                    let (fact1, fact2) = (arr[j], v/arr[j]);

                    let mut prod = match dp.get(&fact1) {
                        Some(&x) => x,
                        None => 0 as i64,
                    };

                    prod = (prod * match dp.get(&fact2) {
                        Some(&x) => x,
                        None => 0 as i64,
                    })%m;
                    
                    
                    let val = dp.get_mut(&v).unwrap();
                    *val = (*val + prod%m)%m;
                }
            }
        }

       let mut sum = 0;
       for (i,v) in dp{
           sum = (sum+v)%m;
       }
         sum as i32
    }
}

