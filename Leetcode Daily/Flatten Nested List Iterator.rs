// #[derive(Debug, PartialEq, Eq)]
// pub enum NestedInteger {
//   Int(i32),
//   List(Vec<NestedInteger>)
// }
pub enum NestedInteger {
  Int(i32),
  List(Vec<NestedInteger>)
}

struct NestedIterator {
    nested_list : Vec<i32>,
    iter : usize,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl NestedIterator {
    fn dfs(nint: &Vec<nested_integer::NestedInteger>, list: &mut Vec<i32>){
        for i in nint{
            match i {
                nested_integer::NestedInteger::Int(x) => {
                    list.push(*x);
                },
                nested_integer::NestedInteger::List(x) => {
                    NestedIterator::dfs(x, list);
                }
            }
        }
    }
    fn new(nestedList: Vec<nested_integer::NestedInteger>) -> Self {
        let mut list: Vec<i32> = Vec::new();
        NestedIterator::dfs(&nestedList, &mut list);
        
        NestedIterator { nested_list: list, iter: 0}
    }
    
    fn next(&mut self) -> i32 {
        self.iter+=1;
        self.nested_list[self.iter-1]     
    }
    
    fn has_next(&self) -> bool {
        self.iter < self.nested_list.len()
    }
}


/**
 * Your NestedIterator object will be instantiated and called as such:
 * let obj = NestedIterator::new(nestedList);
 * let ret_1: i32 = obj.next();
 * let ret_2: bool = obj.has_next();
 */
