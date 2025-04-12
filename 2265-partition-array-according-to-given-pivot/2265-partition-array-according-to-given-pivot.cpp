class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
       int n = nums.size();vector<int> ans(n);
       int l=0,g=n-1;
        for(int i=0,j=n-1;i<n;i++,j--){
            if(nums[i] < pivot)
                ans[l++] = nums[i];
            if(nums[j] > pivot)
                ans[g--] = nums[j];
        }
        while(l <= g){
            ans[l++] = pivot;
        }
        return ans;
    }
};