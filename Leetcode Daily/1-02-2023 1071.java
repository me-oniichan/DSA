import java.util.*;;
class Solution {
    boolean check(String prefix, String str){
        for(int i=0,j=0; i < str.length(); i++,j++){
            j%=prefix.length();
            if(prefix.charAt(j)!=str.charAt(i)) return false;
        }
        return true;
    }
    public int gcd(int a, int b) { return b==0 ? a : gcd(b, a%b); }
    public String gcdOfStrings(String str1, String str2) {
        int g = gcd(str1.length(), str2.length());

        for(int i=g; i>0; i--){
            if(g%i==0){
                String pref = str1.substring(0, i+1);
                if(check(pref, str2) && check(pref, str1)) return pref;
            }
        }

        return "";
    }
}