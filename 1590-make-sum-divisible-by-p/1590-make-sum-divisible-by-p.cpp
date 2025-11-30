class Solution {
public:
    #define ll long long
    int minSubarray(vector<int>& nums, int p) {
        ll sum = 0;
        for (int x : nums) sum += x;

        ll target = sum % p;
        if(target % p == 0)return 0;
        
        unordered_map<ll,int> mp;
        mp[0] = -1;

        ll pre = 0;
        int ans = nums.size();

        for(int i=0;i<nums.size();i++){
            pre = (pre + nums[i]) % p;
            ll need = (pre - target + p) % p;
            if(mp.count(need))
                ans = min(ans,i - mp[need]);
            mp[pre] = i;
        }

        return ans == nums.size() ? -1 : ans;
    }
};