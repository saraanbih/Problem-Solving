class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int find = k-1;
        if(find == 0)return true;
        for(int i=k+1;i<nums.size();i++){
            if(nums[i] > nums[i-1] && nums[i-k] > nums[i-k-1])
                find--;
            else
                find = k-1;
            if(find == 0) return true;
        }
        return false;
    }
};







