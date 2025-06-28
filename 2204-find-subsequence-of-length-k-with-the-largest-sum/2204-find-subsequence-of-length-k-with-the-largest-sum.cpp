class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> v = nums;
        sort(v.begin(),v.end(),greater<int>());
        vector<int> ans;
        unordered_map<int,int> mp;  
        for(int i = 0;i<k;i++){
            mp[v[i]]++;
        }
        for(auto &num : nums){
            if(mp[num]){
                ans.push_back(num);
                mp[num]--;
            }
        }
        return ans;
    }
};