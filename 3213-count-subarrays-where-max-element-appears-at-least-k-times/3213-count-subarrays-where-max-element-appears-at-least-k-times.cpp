class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(),nums.end());
        long long cnt = 0,res = 0;
        int n = nums.size();
        for(int r=0,l=0;r<n;r++){ 
            if(nums[r] == mx)cnt++;
            while(cnt >= k){
               res += (n-r);
               if(nums[l] == mx)cnt--;
               l++;
            }
        }
        return res;
    }
};