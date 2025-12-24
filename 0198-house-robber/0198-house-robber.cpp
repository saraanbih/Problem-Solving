/* Recursive Solution 
    Time: O(2^n)
    Space: O(n)
*/
// class Solution {
// public:
//     int helper(vector<int> &nums,int i){
//         if(i == 0) 
//             return nums[0];
//         if(i == 1)
//             return max(nums[0],nums[1]);
//         return max(nums[i]+helper(nums,i-2),helper(nums,i-1)); 
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();

//         return helper(nums,n-1);
//     }
// };

/* Top Down DP approach
    Time: O(n)
    Space: O(n)
 */
 class Solution {
public:
    vector<int> memo;

    int helper(vector<int> &nums,int i){
        if(i < 0) return 0;
        if(memo[i] != -1)return memo[i];

        memo[i] = max(nums[i] + helper(nums,i-2), helper(nums,i-1));

        return memo[i];
    }

    int rob(vector<int>& nums) {
       int n = nums.size();
       if(n == 0)return 0;

        memo.assign(n,-1);
        return helper(nums,n-1);
    }
};
