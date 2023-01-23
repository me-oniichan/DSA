import java.util.*;
class Solution {
    public int findJudge(int n, int[][] trust) {
        List<List<Integer>> map = new ArrayList<List<Integer>>(n);
        for(int i = 0; i<n; i++) map.add(new ArrayList<Integer>());
        for(int[] i : trust) map.get(i[0]-1).add(i[1]-1);
        int par = -1;
        for(int i = 0; i<n; i++){
            if (map.get(i).isEmpty()){
                par = i;
                break;
            }
        }
        for(int i = 0; i<n; i++){
            if (!map.get(i).contains(par) && i!=par) return -1;
        }
        return par+1;
    }
}   