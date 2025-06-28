class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> v = nums;
        sort(v.begin(),v.end(),greater<int>());
        vector<int> ans;
        unordered_map<int,int> cnt;  
        for(int i = 0;i<k;i++){
            cnt[v[i]]++;
        }
        for(auto &num : nums){
            if(cnt[num]){
                ans.push_back(num);
                cnt[num]--;
            }
        }
        return ans;
    }
};