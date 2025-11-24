class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> ans(n);
        int cur = 0;

        for(int i = 0; i < n; i++){
            cur = (cur * 2 + nums[i]) % 5;
            ans[i] = (cur == 0);
        }

        return ans;
    }
};
