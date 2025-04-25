class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        unordered_map<int,int> cnt;
        long long res = 0;
        cnt[0] = 1;
        int pre = 0;
        for(auto &num : nums){
            pre += num % modulo == k;
            res += cnt[(pre-k+modulo)%modulo];
            cnt[pre%modulo]++;
        }
        return res;
    }
};