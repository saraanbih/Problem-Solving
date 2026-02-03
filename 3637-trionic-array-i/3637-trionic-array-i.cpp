class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        if(nums[0] >= nums[1]) return false;
        int n = nums.size();
        int cnt = 1;

        for(int i=2;i<n;i++){
            if(nums[i-1] == nums[i])return false;
            if((nums[i-2] - nums[i-1]) * (nums[i-1] - nums[i]) < 0)
                cnt++;
        }

        return cnt == 3;
    }
};