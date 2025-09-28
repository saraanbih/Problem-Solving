class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)return 0;

        sort(nums.begin(),nums.end());
        int ans = 0;

        for(int k=n-1;k>=2;k--){
            if(nums[k-2] + nums[k-1] > nums[k])
                return nums[k-2] + nums[k-1] + nums[k];
        }

        return 0; 
    }
};