
// Definition for a QuadTree node.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;

    
    public Node() {
        this.val = false;
        this.isLeaf = false;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }
    
    public Node(boolean val, boolean isLeaf) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }
    
    public Node(boolean val, boolean isLeaf, Node topLeft, Node topRight, Node bottomLeft, Node bottomRight) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = topLeft;
        this.topRight = topRight;
        this.bottomLeft = bottomLeft;
        this.bottomRight = bottomRight;
    }
};


class Solution {
    int grid[][];
    int createTree(int xstart, int xend, int ystart, int yend, Node node){
        if(xstart==xend){
            node.val = grid[ystart][xstart]==1;
            return grid[ystart][xstart];
        }

        int xmid = xstart + (xend - xstart)/2;
        int ymid = ystart + (yend - ystart)/2;

        node.topLeft = new Node();
        node.topRight = new Node();
        node.bottomLeft = new Node();
        node.bottomRight = new Node();

        int topLeft =  createTree(xstart, xmid, ystart, ymid, node.topLeft);
        int bottomLeft = createTree(xstart, xmid, ymid+1, yend, node.bottomLeft);
        int topRight =createTree(xmid+1, xend, ystart, ymid, node.topRight);
        int bottomRight = createTree(xmid+1, xend, ymid+1, yend, node.bottomRight);

        if(topLeft==1 && bottomLeft==1 && topRight==1 && bottomRight==1){
            node.val = true;
            node.isLeaf = true;
            node.topLeft = node.topRight = node.bottomLeft = node.bottomRight = null;
            return 1;
        }
        else if(topLeft==0 && bottomLeft==0 && topRight==0 && bottomRight==0){
            node.val = false;
            node.isLeaf = true;
            node.topLeft = node.topRight = node.bottomLeft = node.bottomRight = null;
            return 0;
        }

        return -1;
    }
    public Node construct(int[][] grid) {
        this.grid = grid;
        Node node = new Node();
        createTree(0, grid.length-1, 0, grid.length-1, node);
        return node;
    }
}