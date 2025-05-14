class Solution {
public:
    int MOD = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
        vector<int> freq(26,0);
        for(auto &ch : s)freq[ch-'a']++;
        while(t--){
            vector<int> nxt(26,0);
            nxt[0] = freq[25]; 
            nxt[1] = (freq[25] + freq[0]) % MOD;
            for(int i = 2;i<26;i++){
                nxt[i] = freq[i-1];
            }
            freq = nxt;
        }
        int ans = 0;
        for(int i = 0;i<26;i++)
            ans = (ans + freq[i])%MOD;
        return ans;
    }
};