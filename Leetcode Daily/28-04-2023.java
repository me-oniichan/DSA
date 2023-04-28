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
    
    void unionn(int p, int q){
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
    public boolean feasible(String a, String b){
        int cunt = 0;
        for(int i=0; i < a.length();i++){
            if(a.charAt(i) != b.charAt(i)) cunt++;
            if(cunt>2) return false;
        }
        return true;
    }

    public int numSimilarGroups(String[] strs) {
        UnionFind uf = new UnionFind(strs.length);
        for(int i=0; i < strs.length; i++){
            for(int j=i+1; j < strs.length; j++){
                if(feasible(strs[i], strs[j])) uf.unionn(i, j);
            }
        }
       return uf.numComponents; 
    }
}