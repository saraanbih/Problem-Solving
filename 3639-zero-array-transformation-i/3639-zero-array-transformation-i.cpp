class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int s = 0, cnt = 0;
        vector<int> v(n + 1, 0); // Difference array

        for (int i = 0; i < n; i++) {
            while (s + v[i] < nums[i]) { // Need more increments
                if (cnt >= queries.size()) return false; // No more queries left

                int l = queries[cnt][0], r = queries[cnt][1];
                cnt++;

                if (r < i) continue; // Skip irrelevant queries
                
                v[max(l, i)]++; // Start increment at max(l, i)
                if (r + 1 < n) v[r + 1]--; // Stop increment at r+1 if valid
            }
            s += v[i]; // Apply the difference array effect
        }
        return true;
    }
};
