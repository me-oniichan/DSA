class Solution {
    public int findKthPositive(int[] arr, int k) {
        int ans=0, prev=0, init=k;
        for(int i : arr){
            int diff = i-prev;
            if(diff==1) {
                prev = i;
                continue;
            }
            
            if(diff > k || k==0){
                ans = prev+k;
                k=0;
                break;  
            }else{
                ans = prev+diff-1;
                k-=(diff-1);
            }
            prev=i;
        }
        if(k>0) return arr[arr.length-1]+k;
        return ans;
    }
}