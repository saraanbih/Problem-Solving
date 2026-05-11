class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) 
    {
       vector<int> res;
       int sz = nums.size() -1;
       for(int i=sz;i>=0;i--)
       {
         while(nums[i] > 0)
         {
            int digit = nums[i] % 10;
            nums[i] /= 10;
            res.push_back(digit);
         }
       }
       reverse(res.begin(),res.end());
       return res;
    }
};