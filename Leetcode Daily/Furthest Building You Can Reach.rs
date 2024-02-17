use std::collections::BinaryHeap;

impl Solution {
    pub fn furthest_building(heights: Vec<i32>, mut bricks: i32, mut ladders: i32) -> i32 {
        let mut pq = BinaryHeap::new();
        
        for i in 0..heights.len()-1{
            let diff = heights[i+1] - heights[i];
            if diff <= 0{
                continue;
            }

            pq.push(diff);
            bricks -= diff;
            if bricks < 0 && ladders > 0{
                bricks += pq.pop().unwrap();
                ladders -= 1;
            }
            if bricks < 0{
                return i as i32;
            }
        }
        heights.len() as i32 - 1
    }
}
