impl Solution {
    pub fn validate_binary_tree_nodes(n: i32, left_child: Vec<i32>, right_child: Vec<i32>)->bool {
        let n = n as usize;
        
        let mut visited = vec![false; n];
        
        for (l, r) in left_child.iter().zip(right_child.iter()){
            if l!=-1{
                visited[l as usize] = true;
            }
            if r!=-1{
                visited[r as usize] = true;
            }
        }
        let mut root = -1;
        for (i,j) in visited.iter().enumerate(){
            if *j==false{
                root=i as i32;
                break;
            }
        }
        if root==-1{
            return false;
        }
        visited = vec![false; n];
        visited[root as usize] = true;
        
        let mut st = vec![root as usize];
        
        while !st.is_empty() {
            let n = st.pop().unwrap();

            let (left, right) = (left_child[n], right_child[n]);

            if left != -1{
                if visited[left as usize]{
                    return false;
                }

                visited[left as usize] = true;
                st.push(left as usize)
            }

            if right != -1{
                if visited[right as usize]{
                    return false;
                }

                visited[right as usize] = true;
                st.push(right as usize);
            }
        }

        visited.iter().filter(|&&x| x==true).count() == n

    }
}
