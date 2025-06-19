class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int mn = INT_MAX,mx = INT_MIN;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(nums[i]<mn)mn=nums[i];
            if(nums[i]>mx)mx=nums[i];
            if(mx-mn>k){
                cnt++;i--;
                mn = INT_MAX,mx = INT_MIN;
            }
        }
        return ++cnt;
    }
};