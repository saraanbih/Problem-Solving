class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> mp(value);
        for(auto &num : nums){
            int v = (num % value + value) % value;
            mp[v]++;
        }
        int mex = 0;
        while(mp[mex % value] > 0){
            mp[mex % value]--;
            mex++;
        }
        return mex;
    }
};