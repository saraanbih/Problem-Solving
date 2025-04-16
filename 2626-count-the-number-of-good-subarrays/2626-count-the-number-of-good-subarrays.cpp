class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0,r=-1;
        long long ans = 0;
        unordered_map<int,int> freq;
        for(int l=0;l<n;l++){
            while(cnt < k && r+1 < n){
                r++;
                cnt += freq[nums[r]]; 
                freq[nums[r]]++;
            }
            if(cnt >= k)ans += n - r;
            --freq[nums[l]];
            cnt -= freq[nums[l]];
        }
        return ans;
    }
};