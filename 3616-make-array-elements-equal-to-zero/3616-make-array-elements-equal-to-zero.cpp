class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        int l = 0,r=0;
        for(auto&num : nums)r+=num;
        for(int i=0;i<n;i++){
            l+=nums[i];
            r-=nums[i];
            if(nums[i] != 0)continue;
            if(l == r) cnt+=2;
            if(abs(l-r) == 1)cnt++;
        }
        return cnt;
    }
};