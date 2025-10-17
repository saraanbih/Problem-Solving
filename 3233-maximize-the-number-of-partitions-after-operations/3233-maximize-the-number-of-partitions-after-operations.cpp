class Solution {
public:
    typedef long long ll;
    unordered_map<long long, int> dp;
    ll solve(ll i, ll mask, ll change, int k, string& s) {
        int n = s.size();
        if (i == n)
            return 1;

        ll cur = (i << 27) | (mask << 1) | (change);

        if (dp.find(cur) != dp.end())
            return dp[cur];

        int val = s[i] - 'a';
        ll nmask = mask | (1 << val);

        int cnt = __builtin_popcount(nmask);

        ll ans = 0;
        ll maxi = 0;

        if (cnt > k) {
            ans = 1 + solve(i + 1, 1 << val, change, k, s);
            maxi = max(maxi, ans);
        } else {
            ans = solve(i + 1, nmask, change, k, s);
            maxi = max(maxi, ans);
        }

        if (change)
            return dp[cur] = maxi;

        for (int j = 0; j < 26; j++) {
            ll nmask = mask | (1 << j);
            int cnt =
                __builtin_popcount(nmask);

            if (cnt > k) {
                maxi = max(maxi, 1 + solve(i + 1, 1 << j, 1, k, s));
            } else {
                maxi = max(maxi, solve(i + 1, nmask, 1, k, s));
            }
        }

        return dp[cur] = maxi;
    }
    int maxPartitionsAfterOperations(string s, int k) {
        return solve(0,0,0,k,s);
    }
};