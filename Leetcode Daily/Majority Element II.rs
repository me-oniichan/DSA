impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> Vec<i32> {
        let mut c1=0;
        let mut c2=0;

        let mut n1=0;
        let mut n2=1;

        for i in nums.iter(){
            if i==&n1{
                c1+=1;
            }
            else if i==&n2 {
                c2+=1;
            }
            else if c1==0{
                n1 = *i;
                c1 = 1;
            }
            else if c2==0{
                n2=*i;
                c2=1;
            }
            else {
                c1-=1;
                c2-=1;
            }
        }

        let mut v = Vec::new();
        if nums.iter().filter(|&i| i==&n1).count() > nums.len()/3{
            v.push(n1);
        }
        if nums.iter().filter(|&i| i==&n2).count() > nums.len()/3{
            v.push(n2);
        }
        v
    }
}
