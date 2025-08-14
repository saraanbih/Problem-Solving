public class Solution {
    public string LargestGoodInteger(string num) {
        string maxGood = "";
        int n = num.Length;
        
        for (int i = 0; i <= n - 3; i++) {
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
                string good = num.Substring(i, 3);
                if (string.Compare(good, maxGood) > 0) {
                    maxGood = good;
                }
            }
        }
        
        return maxGood;
    }
}
