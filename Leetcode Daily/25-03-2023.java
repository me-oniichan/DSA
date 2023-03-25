import java.util.ArrayList;
import java.util.List;

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
    public long countPairs(int n, int[][] edges) {
        UnionFind uf = new UnionFind(n);
        for(int[] i : edges){
            uf.set(i[0], i[1]);
        }

        long pairs=0;
        int[] groupcount = new int[n];
        List<Integer> groups = new ArrayList<>();
        for(int i : uf.parent){
            int par = uf.find(i);
            groupcount[par]++;
            if(groupcount[par]==1) groups.add(par);
        }

        for(int i : groups){
            pairs+= (long)groupcount[i]*(n-groupcount[i]);
            n-=groupcount[i];
        }
        return pairs;
    }
}