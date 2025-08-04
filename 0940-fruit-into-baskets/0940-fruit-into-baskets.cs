public class Solution {
    public int TotalFruit(int[] nums) {
        int left = 0, maxLength = 0;
        Dictionary<int, int> freq = new Dictionary<int, int>();

        for (int right = 0; right < nums.Length; right++)
        {
            int num = nums[right];
            if (!freq.ContainsKey(num))
                freq[num] = 0;
            freq[num]++;

            while (freq.Count > 2)
            {
                int leftNum = nums[left];
                freq[leftNum]--;
                if (freq[leftNum] == 0)
                    freq.Remove(leftNum);
                left++;
            }

            maxLength = Math.Max(maxLength, right - left + 1);
        }

        return maxLength;
    }
}