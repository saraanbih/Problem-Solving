class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size(), parts = k/n;
        vector<vector<int>> ans;
        for(int i = 0;i<n;i+=3){
            if(nums[i+2]-nums[i] > k)return {};
            vector<int> tmp(nums.begin() + i, nums.begin() + i + 3);
            ans.push_back(tmp);
        }
        return ans;
    }
    };