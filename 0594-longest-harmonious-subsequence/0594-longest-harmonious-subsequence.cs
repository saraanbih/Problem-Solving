public class Solution {
    public int FindLHS(int[] nums) {
        Dictionary<int,int> freq = new Dictionary<int,int>();
        foreach(int num in nums){
            if(freq.ContainsKey(num))freq[num]++;
            else freq[num] = 1;
        }

        int ans = 0;
        foreach(var pair in freq){
            int num = pair.Key;
            if(freq.ContainsKey(num + 1))
                ans = Math.Max(ans,freq[num] + freq[num + 1]);
        }
        return ans;
    }
}