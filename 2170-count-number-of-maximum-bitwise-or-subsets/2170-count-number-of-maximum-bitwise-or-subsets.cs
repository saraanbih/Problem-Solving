public class Solution {
    public int CountMaxOrSubsets(int[] nums) {
        List<int> ans = GetAllSubsets(nums);
        int mx = ans.Max();
        return ans.Count(x => x == mx);
    }
    public List<int> GetAllSubsets(int[] nums){
        int n = nums.Length;
        int total = 1 << n;
       
        List<int> ans = new List<int>();
        for(int i = 1;i<total;i++){ 
            int or = 0;
            for(int j=0;j<n;j++){
                if((i & (1 << j)) != 0)
                    or|=nums[j];
            }
            ans.Add(or);
        }
        return ans;
    }
}