import java.util.*;
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}

class Solution {
    public Node cloneGraph(Node node) {
        if(node==null) return null;
        Queue<Node> q = new LinkedList<>();
        Node map[] = new Node[101];
        q.add(node); map[node.val] = new Node(node.val);
        while(!q.isEmpty()){
            Node n = q.poll();
            for(Node i : n.neighbors){
                if(map[i.val]==null) {
                    map[i.val] = new Node(i.val);
                    q.add(i);
                }
                map[n.val].neighbors.add(map[i.val]);
            }
        }
        return map[node.val];
    }
}