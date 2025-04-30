class Solution {
public:
    int findNumbers(vector<int>& nums) {
       int res = 0;
       for(auto &num : nums){
          string str = to_string(num);
          if(str.size()%2==0)res++;
       }
       return res;
    }
};