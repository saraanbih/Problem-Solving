class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        if (power.empty()) return 0;
        map<int, long long> damage;
        for (int p : power) damage[p] += p;

        vector<int> keys;
        vector<long long> vals;
        for (auto &kv : damage) {
            keys.push_back(kv.first);
            vals.push_back(kv.second);
        }
        int n = (int)keys.size();
        vector<long long> dp(n, 0);

        dp[0] = vals[0];
        for (int i = 1; i < n; ++i) {
            int limit = keys[i] - 3;
            auto it = upper_bound(keys.begin(), keys.begin() + i, limit);
            int j = int(it - keys.begin()) - 1; 

            long long take = vals[i] + (j >= 0 ? dp[j] : 0);
            dp[i] = max(dp[i-1], take);
        }
        return dp[n-1];
    }
};
