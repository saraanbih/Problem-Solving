class Solution {
public:
   vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int,int> next_greater;
        stack<int> stk;
        for(int i = nums2.size()-1;i>=0;i--)
        {
            int num = nums2[i];

            while(!stk.empty() && stk.top() <= num)
               stk.pop();
            
            next_greater[num] = stk.empty() ? -1 : stk.top();

            stk.push(num);
        }
        vector<int> res;
        for(auto&num : nums1)
           res.push_back(next_greater[num]);
        
        return res;
    }

};