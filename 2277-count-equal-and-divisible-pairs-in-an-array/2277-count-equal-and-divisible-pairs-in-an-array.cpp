class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        for(auto &pair : mp){
            if(pair.second.size() < 2)continue;
            if(pair.second.size() == 2){
                if((pair.second[0] * pair.second[1]) % k == 0)ans++;
            }
            else{
                for(int i=0;i<pair.second.size();i++){
                    for(int j=i+1;j<pair.second.size();j++){
                        if((pair.second[i] * pair.second[j]) % k == 0)ans++;
                    }
                }
            }
        }
        return ans;
    }
};