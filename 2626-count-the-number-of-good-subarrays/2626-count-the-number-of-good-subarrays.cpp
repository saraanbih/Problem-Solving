class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int p = 0,l = 0,r=-1;
        long long ans = 0;
        for(l;l<nums.size();l++){
            while(p < k && r+1 < nums.size()){
                r++;
                p += freq[nums[r]];
                freq[nums[r]]++;
            }
            if(p >= k)ans+=nums.size()-r;
            freq[nums[l]]--;
            p -= freq[nums[l]];
        }
        return ans;
    }
};