class Solution {
    public int compress(char[] chars) {
        int i=-1, j=1, len=0;
        Integer streak=1;
        for(j=1; j<chars.length; j++){
            if(chars[j]!=chars[j-1]){
                chars[++i] = chars[j-1];
                len++;
                if(streak>1){
                    for(char k: streak.toString().toCharArray()){
                        chars[++i] = k;
                        len++;
                    }
                }
                streak=1;
            }else{
                streak++;
            }
        }
        chars[++i] = chars[j-1];
        len++;
        if(streak>1){
            for(char k: streak.toString().toCharArray()){
                chars[++i] = k;
                len++;
            }
        }
        return len;
    }
}