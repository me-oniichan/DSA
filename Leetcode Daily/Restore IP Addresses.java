//Problem Statement : Restore IP Addresses
import java.util.*;
class Solution {
    List<String> ans = new ArrayList<String>();
    Boolean isvalid(String s){
        //check leading zero
        if(s.equals("0")) return true;
        else if(s.charAt(0) != '0' && Integer.parseInt(s)<=255) return true;
        return false;
    }
    void backtrack(int i, String s, String ip, int dots){
        if(dots == 4){
            if(ip.length()-4 == s.length()) ans.add(ip.substring(0, ip.length()-1));
            return;
        }
        String part = new String();
        for(int j = 0; j<3; j++){
            if(j+i < s.length()){
                part+=s.charAt(j+i);
                if(isvalid(part)) backtrack(i+1+j, s, ip+part+".", dots+1);
            }
        }
    }
    public List<String> restoreIpAddresses(String s) {
        if(s.length() <4 || s.length() > 12) return ans;
        backtrack(0, s, "", 0);
        return ans;
    }
}