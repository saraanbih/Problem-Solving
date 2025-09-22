class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freq;
        int mx = 0;
        for(auto &num : nums){
            freq[num]++;
            mx = max(mx,freq[num]);
        }
        int ans = 0;
        for(auto &pair : freq)
            if(pair.second == mx)ans+=pair.second;
        
        return ans;
    }
};