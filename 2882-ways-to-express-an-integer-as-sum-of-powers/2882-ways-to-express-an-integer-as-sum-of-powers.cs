public class Solution {
    private const int MOD = 1_000_000_007;
    public int NumberOfWays(int n, int x) {
        long[,] dp = new long[n+1,n+1];
        dp[0,0] = 1;
        for(int i = 1;i<=n;i++){
            long val = (long)Math.Pow(i,x);
            for(int j = 0;j<=n;j++){
                dp[i,j] = dp[i-1,j];
                if(j>=val)
                    dp[i,j] = (dp[i,j] + dp[i-1,j-(int)val]) % MOD;      
            }
        }
        return (int)dp[n,n];
    }
}