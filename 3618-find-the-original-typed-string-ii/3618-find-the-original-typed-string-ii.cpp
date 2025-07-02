class Solution {
    static const int MOD = 1e9 + 7;
public:
    int possibleStringCount(string word, int k) {
        if (word.empty()) return 0;

        vector<int> g;
        int cnt = 1;
        for (size_t i = 1; i < word.size(); ++i) {
            if (word[i] == word[i - 1]) cnt++;
            else {
                g.push_back(cnt);
                cnt = 1;
            }
        }
        g.push_back(cnt);

        long long t = 1;
        for (int num : g)
            t = (t * num) % MOD;

        if (k <= (int)g.size()) return t;

        vector<int> dp(k, 0);
        dp[0] = 1;

        for (int num : g) {
            vector<int> newDp(k, 0);
            long long s = 0;
            for (int i = 0; i < k; ++i) {
                if (i > 0) s = (s + dp[i - 1]) % MOD;
                if (i > num) s = (s - dp[i - num - 1] + MOD) % MOD;
                newDp[i] = s;
            }
            dp = newDp;
        }

        long long not_valid = 0;
        for (int i = g.size(); i < k; ++i)
            not_valid = (not_valid + dp[i]) % MOD;

        return (t - not_valid + MOD) % MOD;
    }
};