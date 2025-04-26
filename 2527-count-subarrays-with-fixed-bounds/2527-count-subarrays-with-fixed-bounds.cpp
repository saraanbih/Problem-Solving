class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int mn = -1,mx = -1,left = -1;
        long long ans = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] < minK || nums[i] > maxK){
                left = i;
                mn = mx = -1;
            }
            if(nums[i] == minK) mn = i;
            if(nums[i] == maxK) mx = i;
            if(mn != -1 && mx != -1){
                ans += max(0,min(mn,mx)-left);
            }
        }
        return ans;
    }
};