struct MountainArray;
impl MountainArray {
    fn get(index:i32)->i32;
    fn length()->i32;
}


impl Solution {
    pub fn find_in_mountain_array(target: i32, mountain_arr: &MountainArray) -> i32 {
        let mut left = 0;
        let size = mountain_arr.length();
        let mut right = size-1;

        while left < right{
            let mid = (left+right)/2;
            let elem = mountain_arr.get(mid);
            let next = mountain_arr.get(mid+1);

            if elem < next{
                left = mid+1;
            }
            else {
                right = mid;
            }
        }

        left = 0;

        while left <= right {
            let mid = (left+right)/2;
            let elem = mountain_arr.get(mid);
            if elem == target{
                return mid;
            }
            else if elem < target {
                left = mid+1;
            }
            else {
                right = mid-1;
            }
        }

        right = size-1;

        while left <= right {
            let mid = (left+right)/2;
            let elem = mountain_arr.get(mid);
            if elem == target{
                return mid;
            }
            else if elem < target{
                right = mid-1;
            }
            else {
                left = mid+1;
            }
        }

        -1

    }
}
