import java.util.Arrays;

class Solution {static int lower_bound(int array[], int key)
    {
        int low = 0, high = array.length;
        int mid;
 

        while (low < high) {
            mid = low + (high - low) / 2;
            if (key <= array[mid]) {
                high = mid;
            }
 
            else {
 
                low = mid + 1;
            }
        }
 
        if (low < array.length && array[low] < key) {
            low++;
        }
        return low;
    }
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        int ans[] = new int[spells.length], size = potions.length;
        Arrays.sort(potions);
        for(int i = 0; i< spells.length; i++){
            long req = (success + spells[i] - 1) / spells[i];
            if(req > Integer.MAX_VALUE) {
                ans[i] = 0;
                continue;
            }
            int index = lower_bound(potions, (int)req);
            ans[i] = size-index;
        }
        return ans;
    }
}