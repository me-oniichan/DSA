import java.util.HashMap;
import java.util.Map;

class Solution {
    public int longestCycle(int[] edges) {
        int ans=-1;
        boolean[] visited = new boolean[edges.length];

        for(int i = 0; i < edges.length; i++){
            if(!visited[i]){
                int node = i;
                Map<Integer, Integer> map = new HashMap<>();
                map.put(i, 1);
                while(true){
                    visited[node] = true;
                    int next = edges[node];
                    if(next!=-1 && !visited[next]){
                        map.put(next, map.get(node)+1);
                        node = next;
                    }
                    else if(next!=-1 && map.containsKey(next)){
                        ans = Math.max(ans, map.get(node)-map.get(next)+1);
                        break;
                    }
                    else break;
                }
            }
        }

        return ans;
    }
}