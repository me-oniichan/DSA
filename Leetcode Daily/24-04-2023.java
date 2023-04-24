import java.util.Comparator;
import java.util.PriorityQueue;

class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> q = new PriorityQueue<>(Comparator.reverseOrder());
        for(int i : stones) q.add(i);
        while(q.size() >  1){
            int y= q.poll(), x = q.poll();
            if(x!=y) q.add(y-x);
        }

        return q.size()==1? q.peek(): 0;
    }
}