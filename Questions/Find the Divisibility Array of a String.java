class Solution {
    public int[] divisibilityArray(String word, int m) {
        int[] ans = new int[word.length()];
        long num=0, r=0;
        for(int i=0; i < word.length(); i++){
            num = r*10+word.charAt(i)-48;
            r = num%m;
            if(r==0) ans[i]=1;
        }
        return ans;
    }
}