class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int m=0;m<(1 << n);m++){
            int var = 0;
            for(int i=0;i<n;i++){
                if(m & (1 << i))var^=nums[i];
            }
            ans += var;
        }
        return ans;
    }
};