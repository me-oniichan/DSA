import java.util.Arrays;

class Solution {
    boolean isValid(int[] piles, int h, double k){
        for(double i : piles){
            h-=Math.ceil(i/k);
            if(h<0) return false;
        }
        return true;
    }
    public int minEatingSpeed(int[] piles, int h) {
        int min = 1, max = Arrays.stream(piles).max().getAsInt();
        while(min < max){
            int mid = min+(max-min)/2;
            if(isValid(piles, h, mid)) max=mid;
            else min=mid+1;
        }
        return min;
    }
}