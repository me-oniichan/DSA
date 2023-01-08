import java.util.*;

class Solution {
    public int maxPoints(int[][] points) {
        int line = 0;
        for (int i = 0; i < points.length; i++) {
            HashMap<Double, Integer> m = new HashMap<Double, Integer>();
            for (int j = i+1; j < points.length; j++) {
                double slope = 1000000007;
                if (points[i][0] - points[j][0] != 0){
                    slope = (double)(points[i][1] - points[j][1])/(double)(points[i][0] - points[j][0]);
                }
                m.putIfAbsent(slope, 1);
                m.put(slope, m.get(slope)+1);
            }
            int point = 0;
            for (int val : m.values()){
                if(val > point) point = val;
            }

            line = point > line? point : line;
        }
        return line;
    }
}