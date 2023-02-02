import java.util.*;

class Solution {
    public int[] indices = new int[26];
    public boolean check(String a, String b){
        for(int i=0; i < Math.min(a.length(), b.length()); i++){
            if(indices[a.charAt(i)-'a'] == indices[b.charAt(i)-'a']) continue;
            else return indices[a.charAt(i)-'a'] <= indices[b.charAt(i)-'a'];
        }
        return a.length() <= b.length();
    }
    public boolean isAlienSorted(String[] words, String order) {
        for(int i=0 ; i < order.length(); i++) indices[order.charAt(i)-'a'] = i;

        for(int i=1; i < words.length; i++){
            if(!check(words[i-1], words[i])) return false;
        }
        return true;
    }
}
