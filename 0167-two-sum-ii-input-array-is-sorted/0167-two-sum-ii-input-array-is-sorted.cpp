class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int right=0,left=numbers.size()-1;
        while(right < left)
        {
            int sum = numbers[right] + numbers[left];

            if(sum == target) return {right+1,left+1};
            if(sum > target) left--;
            else
              right++;
        }
        return {};
        
    }
};