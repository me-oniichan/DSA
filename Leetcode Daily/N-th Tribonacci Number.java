class Solution {
    public int tribonacci(int n) {
        int[] arr = {0,0,1};
        for(int i=0; i < n; i++){
            int sum = arr[0]+arr[1]+arr[2];
            arr[2] = arr[1];
            arr[1] = arr[0];
            arr[0] = sum;
        }
        return arr[0];
    }
}