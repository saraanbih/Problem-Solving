class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& st,
                    vector<int>& ed) {
        int n = st.size(), res = 0;
        vector<int> sum(n + 1);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + ed[i] - st[i];
        }
        for (int i = k - 1; i < n; i++) {
            int right = i == n - 1 ? eventTime : st[i + 1];
            int left = i == k - 1 ? 0 : ed[i - k];
            res = max(res, right - left - (sum[i + 1] - sum[i - k + 1]));
        }
        return res;
    }
};