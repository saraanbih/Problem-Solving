class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        for(int num : nums){
            ans.push_back(num);

            while(ans.size() > 1){
                int a = ans[ans.size() - 1];
                int b = ans[ans.size() - 2];
                int g = gcd(b,a%b);
                if(g > 1){
                    long long l = lcm((long long)a,(long long)b);
                    ans.pop_back();
                    ans.pop_back();
                    ans.push_back(l);
                }
                else
                    break;
            }
        }
        return ans;
    }
};