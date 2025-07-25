public class Solution {
    public int MaxSum(int[] nums) {
        HashSet<int> unique = new HashSet<int>();
        int sum = 0;
        foreach(int num in nums){
            if(num < 0 || unique.Contains(num))continue;
            unique.Add(num);
            sum+=num;
        }
        if(unique.Count == 0)
            return nums.Max();
        return sum;
    }
}