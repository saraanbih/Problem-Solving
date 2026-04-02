class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int sz = nums.size();
        int cnt = 0;
        int l=0;
        for(int i=0;i<sz;i++){
            if(nums[i] != val){
                nums[l] = nums[i];
                l++;
                cnt++;
            }
        }
        return cnt;
    }
};