use std::mem::swap;

struct UnionFind{
    parent : Vec<usize>,
    rank : Vec<usize>,
    groups : usize,
}
impl UnionFind{
    pub fn new(size : usize){
        let mut pars = vec![0;size];
        let mut r = vec![0;size];
        let mut idx = 0;
        for i in &pars{
            *i = idx;
            idx+=1;
        }

        UnionFind {
            parent : pars,
            rank : r,
            groups : pars.len(),
        }
    }

    pub fn find(&self, x : usize) -> usize{
        if x!= self.parent[x as  usize]{
            self.parent[x] = self.find(self.parent[x]);
        }

        self.parent[x]
    }

    pub fn  union(&self, x : usize, y: usize){
        let mut rootx = self.find(x);
        let mut rooty = self.find(y);

        if rooty != rootx{
            if self.rank[rootx] < self.rank[rooty]{
                swap(&mut rootx, &mut rooty);
            }

            self.parent[rooty] = rootx;
            self.rank[rootx] += self.rank[rooty];

            self.groups-=1;
        }
    }

}

impl Solution {
    pub fn find_critical_and_pseudo_critical_edges(n: i32, edges: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
                 
    }
}
