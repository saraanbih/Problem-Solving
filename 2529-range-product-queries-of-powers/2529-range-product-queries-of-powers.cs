public class Solution {
    private const int MOD = 1000000007;

    public int[] ProductQueries(int n, int[][] queries) {
        var bins = new List<int>();
        int rep = 1;
        while (n > 0) {
            if (n % 2 == 1) {
                bins.Add(rep);
            }
            n /= 2;
            rep *= 2;
        }

        int[] ans = new int[queries.Length];
        for (int i = 0; i < queries.Length; i++) {
            long cur = 1;
            int start = queries[i][0];
            int end = queries[i][1];
            for (int j = start; j <= end; ++j) {
                cur = (cur * bins[j]) % MOD;
            }
            ans[i] = (int)cur;
        }
        return ans;
    }
}