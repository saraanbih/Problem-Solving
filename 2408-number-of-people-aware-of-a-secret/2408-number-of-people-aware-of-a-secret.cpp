class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int MOD = 1e9 + 7;
        vector<long long> dp(n+1,0);
        dp[1] = 1;
        long long share = 0;
        for(int d = 2;d<=n;d++){
            int st = d - delay;
            if(st >= 1)
                share = (share + dp[st])%MOD;
            
            int f = d - forget;
            if(f >= 1)
                share = (share - dp[f] + MOD)%MOD;
            
            dp[d] = share; 
        }
        long long ans = 0;
        for(int i = n - forget + 1;i<= n;i++){
            if(i >= 1)
                ans = (ans + dp[i])%MOD;
        }
        return (int)ans;
    }
};