public class Solution {
    public string MakeFancyString(string s) {
        StringBuilder ans = new StringBuilder();
        int freq = 1;
        ans.Append(s[0]);
        for(int i=1;i<s.Length;i++){
            if(s[i]==s[i-1])freq++;
            else freq = 1;
            if(freq > 2)continue;
            ans.Append(s[i]);
        }
        return ans.ToString();
    }
}