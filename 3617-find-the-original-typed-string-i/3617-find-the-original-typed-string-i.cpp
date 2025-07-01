class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 0,cnt = 1;
        char ch = word[0];
        for(int i = 1;i<word.length();i++){
            if(ch == word[i]){
                ch = word[i];
                cnt++;
                for(int j = i+1;j<word.length();j++){
                    if(ch!=word[j])break;
                    cnt++;
                    ch = word[j];
                }
                i += (cnt - 1);
            }
            ch = word[i];
            ans += (cnt - 1);
            cnt = 1;
        }
        return (ans == 0 ? 1 : ans + 1);
    }
};