class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int start = 0, reserve = 0, min = gas[0] - cost[0];
        for (int i = 0; i < cost.length; i++) {
            int req = gas[i] - cost[i];
            reserve+=req;
            if (min > reserve){
                start = i;
                min = reserve;
            }
        }
        if(reserve<0) return -1;
        else return (start+1)%cost.length;
    }
}