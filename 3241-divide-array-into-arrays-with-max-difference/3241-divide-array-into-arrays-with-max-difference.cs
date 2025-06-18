public class Solution {
    public int[][] DivideArray(int[] nums, int k) {
        Array.Sort(nums);
        int n = nums.Length;
        List<int[]> ans = new List<int[]>();
        for(int i=0;i<n;i+=3){
            if(nums[i+2] - nums[i] > k)return new int[0][];
            ans.Add(new int[] {nums[i] , nums[i+1] , nums[i+2]});
        }
        return ans.ToArray();
    }
}