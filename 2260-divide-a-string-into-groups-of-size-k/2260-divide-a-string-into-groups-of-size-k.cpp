class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.length();
        for(int i=0;i<= n - k;i+=k){
            string sub = s.substr(i,k);
            ans.push_back(sub);
        }
        int rem = n % k;
        if(rem != 0){
            int idx = n - rem;
            string sub = s.substr(idx,n);
            for(int i=sub.length();i<k;i++)sub+=fill;
            ans.push_back(sub);
        }
        
        return ans;
    }
};