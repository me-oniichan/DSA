class Solution {
    public int partitionString(String s) {
        int ans=0, map[]=new int[26];

        for(char c : s.toCharArray()){
            if(map[c-'a']==1){
                ans++;
                map = new int[26];
            }
            map[c-'a']++;
        }

        return ans+1;       
    }
}