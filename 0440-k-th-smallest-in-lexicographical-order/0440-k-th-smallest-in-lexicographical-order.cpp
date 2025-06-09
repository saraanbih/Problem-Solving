class Solution {
public:
    #define ll long long
    long long cal(ll cur,ll n){
        ll nxt = cur + 1;
        ll steps = 0;
        while(cur<=n){
            steps += min(n+1,nxt) - cur;
            cur *= 10;
            nxt *= 10;
        }
        return steps;
    }
    int findKthNumber(int n, int k) {
        int cur = 1;
        k--;
        while(k > 0){
            int steps = cal(cur,n);
            if(steps <= k){
                cur++;
                k-=steps;
            }else{
                cur*=10;
                k--;
            }
        }
        return cur;
    }
};