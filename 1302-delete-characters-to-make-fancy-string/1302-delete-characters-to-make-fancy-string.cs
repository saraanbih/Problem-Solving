public class Solution {
    public string MakeFancyString(string s) {
        StringBuilder ans = new StringBuilder();
        ans.Append(s[0]);
        for(int i=1;i<s.Length;i++){
            int len = ans.Length;
            if(len >= 2 && s[i] == s[i-1] && s[i] == s[i-2])
                continue;
            ans.Append(s[i]);
        }
        return ans.ToString();
    }
}