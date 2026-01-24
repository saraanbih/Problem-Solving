class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l = n/2 - 1, r = n/2;
        int mx = 0;
        while(l >= 0 && r < n){
            mx = max(mx,nums[l]+nums[r]);
            l--;
            r++;
        }
        return mx;
    }
};