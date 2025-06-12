class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int mx_ans = INT_MIN;
        int n = nums.size();
        for(int i=1;i<n;i++)
            mx_ans = max(mx_ans,abs(nums[i-1]-nums[i]));
        mx_ans = max(mx_ans,abs(nums[n-1]-nums[0]));
        return mx_ans;
    }
};