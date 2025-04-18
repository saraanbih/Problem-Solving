class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string str = "1";
        for(int i=2;i<=n;i++){
            string tmp = "";
            int cnt = 1;
            for(int j = 1;j<str.length();j++){
                if(str[j]!=str[j-1]){
                    tmp += (to_string(cnt) + str[j-1]);
                    cnt = 1;
                }
                else cnt++;
            }
            str = tmp + (to_string(cnt) + str.back());
        }
        return str;
    }
};