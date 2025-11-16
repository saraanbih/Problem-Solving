class Solution {
public:
    #define ll long long
    ll MOD = 1e9 + 7;
    int numSub(string s) {
        ll ans = 0;
        ll cnt = 0;
        //1's => cnt*cnt+1/2 

        for(auto &ch : s){
            if(ch == '1')cnt++;
            else{
                ans = (ans + (cnt*(cnt+1)/2) % MOD) % MOD;
                cnt = 0;
            }
        }

        if(cnt > 0)
            ans = (ans + (cnt*(cnt+1)/2) % MOD) % MOD;
        
        return ans;

    }
};