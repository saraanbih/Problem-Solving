class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        int n = d.size();
        int cnt = 0;
        for(int i=n-1;i>=0;i--){
            if(d[i] == 9)cnt++;
            else break;
        }
        if(cnt == 0){
            d[n-1]++;
            return d;
        }
        bool chk = false;
        if(cnt == n){
            chk = true;
            d.resize(n+1);
        } 
        n = d.size();
        while(cnt--){
            d[n-1]=0;
            n--;
        }
        if(!chk)d[n-1] += 1;
        else d[n-1] = 1;
        return d;
    }
};