public class Solution {
    public int LongestSubarray(int[] nums) {
        int mx = nums.Max();
        int ans = 0;
        int n = nums.Length;
        for(int i = 0;i<n;i++){
            int var = 0;
            if(nums[i] == mx){
                while(i < n && nums[i++] == mx){
                    var++;
                }
            }
            ans = Math.Max(ans,var);
        }
        return ans;
    }
}