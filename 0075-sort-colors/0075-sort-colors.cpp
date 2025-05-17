class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0 = 0,cnt1 = 0,cnt2=0;
        for(auto &num : nums){
            if(num == 0)cnt0++;
            else if(num == 1)cnt1++;
            else cnt2++;
        }
        for(int i=0;i<nums.size();i++){
            if(cnt0-->0)nums[i] = 0;
            else if(cnt1-->0)nums[i]=1;
            else if(cnt2-->0) nums[i] = 2;
        }
    }
};