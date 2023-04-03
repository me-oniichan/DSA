import java.util.Arrays;

class Solution {
    public int numRescueBoats(int[] people, int limit) {
        int ans=0, size = people.length;
        Arrays.sort(people);

        for(int i=0, j=size-1; i<=j;j--){
            if(people[i]+people[j] <=limit) i++;
            ans++;
        }
        
        return ans;
    }
}