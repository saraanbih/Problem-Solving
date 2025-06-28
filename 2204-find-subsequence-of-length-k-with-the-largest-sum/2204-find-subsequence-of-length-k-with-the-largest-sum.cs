public class Solution {
    public int[] MaxSubsequence(int[] nums, int k) {
        int[] arr = nums.OrderByDescending(x => x).ToArray();
        Dictionary<int,int> cnt = new Dictionary<int,int>();
        for(int i = 0;i<k;i++){
            if (!cnt.ContainsKey(arr[i]))
                cnt[arr[i]] = 0;
            cnt[arr[i]]++;
        } 
        List<int> ans = new List<int>();
        foreach(int num in nums){
            if(cnt.ContainsKey(num) && cnt[num] > 0){
                ans.Add(num);
                cnt[num]--;
            }
        }
        return ans.ToArray();
    }
}