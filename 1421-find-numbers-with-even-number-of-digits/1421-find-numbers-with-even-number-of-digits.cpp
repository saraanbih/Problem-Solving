class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for(auto &num : nums){
            int cnt = 0;
            while(num){
                cnt++;
                num/=10;
            }
            if(cnt%2==0)res++;
        }
        return res;
    }
};