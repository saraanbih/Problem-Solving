class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n,0);
        for(int i=n-1;i>=0;i--){
            dp[i] = energy[i] + (i + k < n ? dp[i+k] : 0);
        }
        sort(dp.begin(),dp.end());
        return dp[n-1];
    }
};