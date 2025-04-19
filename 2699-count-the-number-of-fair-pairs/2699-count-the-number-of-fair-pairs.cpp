class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
       sort(nums.begin(),nums.end());
       int n = nums.size();
       long long cnt = 0;

       for(int i = 0;i<n;i++){
           auto l = lower_bound(nums.begin()+i+1,nums.end(),lower - nums[i]);
           auto r = upper_bound(nums.begin()+i+1,nums.end(),upper - nums[i]);

           cnt += (r-l);
       }
       return cnt;
    }
};