class UnionFind{
    int num;
    int numComponents;
    int[] rank, parent;
    UnionFind(int n){
        num = n; numComponents = n;
        rank = new int[n];
        parent = new int[n];
        for(int i = 0; i<n; i++) parent[i] = i;
    }
    
    int size(){return num;}
    
    int components(){return numComponents;}
    
    int find(int p){
        while(p != parent[p]){
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }
    
    void set(int p, int q){
        int rootp = find(p); int rootq = find(q);
        if(rootp == rootq) return;
        if(rank[rootp] < rank[rootq]) parent[rootp] = rootq;
        else{
            parent[rootq] = rootp;
            if(rank[rootp] == rank[rootq]){rank[rootp]++;}
        }
        numComponents--;
    }
    
    boolean connected(int p, int q){
        return find(p) == find(q);
    }
};

class Solution {
    public int closedIsland(int[][] grid) {
        int rows=grid.length, cols=grid[0].length;
        UnionFind uf = new UnionFind(rows*cols);

        for(int i=0;i<rows;i++){
            uf.set(i*cols, 0);
            uf.set(i*cols+cols-1, 0);
        }

        for(int i=1;i<cols;i++){
            uf.set(i, 0);
            uf.set((rows-1)*cols+i, 0);
        }

        for(int i=1; i < rows; i++){
            for(int j=1; j<cols; j++){
                if(grid[i][j]==0){
                    if(grid[i-1][j]==0) uf.set(i*cols+j, (i-1)*cols+j);
                    if(grid[i][j-1]==0) uf.set(i*cols+j, i*cols+j-1);
                }else uf.set(i*cols+j, 0);
            }
        }

        return uf.numComponents-1;
    }
}