class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int l = i+1,r=n-1;
            while(l<r){
                int s = nums[i]+nums[r]+nums[l];
                if(s == 0){
                    res.push_back({nums[i],nums[r],nums[l]});
                    while(l < r && nums[l] == nums[l+1]) l++;
                    while(l < r && nums[r] == nums[r-1]) r--;

                    l++; r--;
                }
                else if(s > 0) r--;
                else l++; 
            }
        }
        return res;
    }
};