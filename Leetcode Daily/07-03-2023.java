import java.util.Arrays;

class Solution {
    boolean isvalid(Long req, int[] time, int totalTrips){
        int trips=0;
        for(int i : time){
            trips+=(req/i);
            if(trips>= totalTrips) return true;
        }
        return false;
    }
    public long minimumTime(int[] time, int totalTrips) {
        long mintime = 1, maxtime = Arrays.stream(time).min().getAsInt()*totalTrips;
        while(mintime<maxtime){
            Long mid = (mintime+maxtime)/2;
            if(isvalid(mid, time, totalTrips)) maxtime=mid;
            else mintime=mid+1;
        }
        return mintime;
    }
}