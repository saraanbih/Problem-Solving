class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for(auto &n : nums){
            int d = 0;
            while(n){
                d++;
                n/=10;
            }
            if(d%2==0)res++;
        }
        return res;
    }
};