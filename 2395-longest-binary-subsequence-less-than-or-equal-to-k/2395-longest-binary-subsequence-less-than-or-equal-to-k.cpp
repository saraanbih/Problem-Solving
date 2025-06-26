class Solution {
public:
    int longestSubsequence(string s, int k) {
        int cnt = 0;
        int n = s.length();
        long long base = 1,val = 0;
        for(auto&ch : s){
            if(ch == '0')cnt++;
        }
        for(int i = n-1;i>=0;i--){
            if(s[i] == '1'){
                if(val + base > k)continue;
                val += base;
                cnt++;
            }
            base <<= 1;
            if(base > k)break;
        }
        return cnt;
    }
};
