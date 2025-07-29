public class Solution {
    public int[] SmallestSubarrays(int[] nums) {
        int n = nums.Length;
        int[] pos = new int[31];
        Array.Fill(pos,-1);
        int[] ans = new int[n];
        for(int i = n-1;i>=0;i--){
            int j = i;
            for(int bit = 0;bit<31;++bit)
            if((nums[i] & (1 << bit)) == 0){
                if(pos[bit] != -1)
                    j = Math.Max(j,pos[bit]);
            }
            else
                pos[bit] = i;
            
            ans[i] = j - i + 1;
        }
        return ans;
    }
}