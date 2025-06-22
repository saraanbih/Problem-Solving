class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.length();
        int i = 0;
        while(i < n){
            string sub = "";
            for(int j=0;j< k;++j){
                if(i<n)
                    sub+=s[i++];
                else
                    sub+=fill;
            }
            ans.push_back(sub);
        }
       
        
        return ans;
    }
};