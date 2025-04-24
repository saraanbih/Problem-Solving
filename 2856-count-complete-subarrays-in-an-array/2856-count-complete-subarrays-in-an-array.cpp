class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        int cnt = 0;
        int l=0,r=0;
        for(l;l<nums.size();l++){
            mp[nums[l]]++;
            while(mp.size() == s.size()){
                cnt += (nums.size() - l);
                mp[nums[r]]--;
                if(mp[nums[r]] == 0)mp.erase(nums[r]);
                r++;
            }
        }
        return cnt;
    }
};