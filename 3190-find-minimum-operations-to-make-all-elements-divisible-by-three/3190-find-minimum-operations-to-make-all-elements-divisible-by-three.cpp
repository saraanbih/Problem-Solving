class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for(auto &num : nums){
            if(num % 3 == 0)continue;
            ans += (min(num%3, 3 - (num % 3)));
        }
        return ans;
    }
};