class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int mx = *max_element(nums.begin(),nums.end()) + k + 2;
        int* cnt = new int[mx]();
        for(int v : nums)
            cnt[v]++;
        
        for(int i=1;i<mx;i++)
            cnt[i] += cnt[i-1];

        int res = 0;
        for(int i=0;i<mx;i++){
            int l = max(0,i-k);
            int r = min(mx - 1,i+k);
            int total = cnt[r] - (l ? cnt[l-1] : 0);
            int freq = cnt[i] - (i ? cnt[i-1] : 0);
            res = max(res,freq + min(numOperations,total - freq));
        }

        return res;
    }
};