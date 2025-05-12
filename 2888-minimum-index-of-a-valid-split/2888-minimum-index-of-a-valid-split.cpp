class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(auto &n : nums)freq[n]++;
        int sz = nums.size(),dom = -1;
        for(auto & pair: freq){
            if(pair.second > sz / 2) {
                dom = pair.first;
                break;
            }
        }
        int cnt = 0;
        for(int i=0;i<sz-1;i++){
            if(nums[i] == dom)cnt++;
            if((cnt > (i+1)/2) && (freq[dom] - cnt > (sz-i-1)/2)) return i;
        }
        return -1;
    }
};
