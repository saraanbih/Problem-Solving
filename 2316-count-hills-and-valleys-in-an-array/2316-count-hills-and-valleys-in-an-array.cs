public class Solution {
    public int CountHillValley(int[] nums) {
        List<int> arr = new List<int>();
        arr.Add(nums[0]);
        for(int i = 1;i<nums.Length;i++){
            if(nums[i]!=nums[i-1])
                arr.Add(nums[i]);
        }
        int cnt = 0;
        for(int i = 1;i<arr.Count - 1;i++){
            if((arr[i]<arr[i-1]) && (arr[i]>arr[i+1]))
                continue;
            if((arr[i]>arr[i-1]) && (arr[i]<arr[i+1]))
                continue;
            cnt++;
        }
        return cnt;
    }
}