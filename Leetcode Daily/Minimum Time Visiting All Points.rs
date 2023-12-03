impl Solution {
    pub fn min_time_to_visit_all_points(points: Vec<Vec<i32>>) -> i32 {
        let mut prev = points.first().unwrap().clone();
        let mut ans = 0;

        for point in points{
            ans += (point[0] - prev[0]).abs().max((point[1]-prev[1]).abs());
            prev = point;
        }
        ans
    }
}
