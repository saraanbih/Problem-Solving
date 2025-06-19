class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int cnt = 0;
        for(int i=0;i<n;){
            int st = nums[i];
            cnt++;
            while(i<n && nums[i] - st <= k)i++;
        }
        return cnt;
    }
};