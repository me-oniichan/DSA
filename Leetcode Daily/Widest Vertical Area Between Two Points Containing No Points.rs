impl Solution {
    pub fn max_width_of_vertical_area(mut points: Vec<Vec<i32>>) -> i32 {
        points.sort_unstable();
        let mut ans = 0;

        let mut prev = points[0][0];
        for i in 1..points.len(){
            ans = ans.max(points[i][0] - prev);
            prev = points[i][0];
        }

        ans
    }
}
