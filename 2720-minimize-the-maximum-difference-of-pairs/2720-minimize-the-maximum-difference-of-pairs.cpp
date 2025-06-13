class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int l = 0,r = nums[n-1] - nums[0];
        while(l < r){
            int md = (l+r) / 2;
            int cnt = 0;
            for(int i=1;i<n;i++){
                if(nums[i] - nums[i-1] <= md){
                    cnt++; i++;
                }
            }
            if(cnt>=p)r=md;
            else l=md+1;
        }
        return l;
    }
};