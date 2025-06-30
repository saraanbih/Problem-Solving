class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(auto &num : nums)freq[num]++;

        int ans = 0;
        for(auto &pair : freq){
            int num = pair.first;
            if(freq.count(num+1))
                ans = max(ans,freq[num] + freq[num + 1]);
        }
        return ans;
    }
};