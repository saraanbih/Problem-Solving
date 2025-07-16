public class Solution {
    public int MaximumLength(int[] nums) {
        int od = 0;
        int ev = 0;
        foreach(int num in nums){
            if(num%2 == 1)od++;
            else ev++;
        }

        int alt1 = 0; 
        int last1 = -1;
        foreach(int num in nums){
            int p = num % 2;
            if(alt1 == 0 || p != last1){
                alt1++;
                last1 = p;
            }
        }

        int alt2 = 0;
        int last2 = -1;
        foreach(int num in nums){
            int p = num % 2;
            if(alt2 == 0 || p != last2){
                alt2++;
                last2 = p;
            }
        }

        return Math.Max(Math.Max(od,ev),Math.Max(alt1,alt2));
        
    }
}