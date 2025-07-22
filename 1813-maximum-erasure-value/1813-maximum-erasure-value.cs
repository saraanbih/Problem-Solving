public class Solution {
    public int MaximumUniqueSubarray(int[] nums) {
        int n = nums.Length;
        int l = 0, r =0;
        int mx = 0,s =0;

        HashSet<int> unique = new HashSet<int>();

        while(r < n){
            while(unique.Contains(nums[r])){
                s-=nums[l];
                unique.Remove(nums[l]);
                l++;
            }
            s+=nums[r];
            unique.Add(nums[r]);
            r++;
            mx = Math.Max(mx,s);
        }

        return mx;
    }
}