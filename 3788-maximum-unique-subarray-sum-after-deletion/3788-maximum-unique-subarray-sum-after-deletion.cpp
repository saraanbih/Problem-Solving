class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> unique;
        int sum = 0;
        for(auto &num:nums){
            if(unique.count(num) || num < 0)continue;
            unique.insert(num);
            sum+=num;
        }
        if(unique.size() == 0)
            return *max_element(nums.begin(),nums.end());  
        return sum;
    }
};