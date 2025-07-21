class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int freq = 1;
        ans += s[0];
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1])freq++;
            else freq = 1;
            if(freq > 2)continue;
            ans += s[i];
        }
        return ans;
    }
};