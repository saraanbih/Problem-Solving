class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& st, vector<int>& ed) {
        int n = st.size();
        vector<bool> q(n);
        for(int i=0,t1 = 0,t2 = 0; i< n;i++){
            if(ed[i] - st[i] <= t1)q[i]=true;
            t1 = max(t1,st[i] - (i == 0 ? 0 : ed[i-1]));
            if(ed[n-i-1] - st[n-i-1] <= t2)q[n-i-1]=true;
            t2 = max(t2,(i == 0? eventTime : st[n-i]) - ed[n - i - 1]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int l = i == 0 ? 0 : ed[i-1];
            int r = i == n - 1 ? eventTime : st[i+1];
            if(q[i])
                ans = max(ans, r - l);
            else
                ans = max(ans,r - l - (ed[i] - st[i]));
        }
        return ans;
    }
};