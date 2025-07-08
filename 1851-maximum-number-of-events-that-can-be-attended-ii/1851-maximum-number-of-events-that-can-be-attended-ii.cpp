class Solution {
public:
    // Sort events before calling this
    int nxt(const vector<vector<int>>& events, int cur) {
        int l =0,h = events.size();
        while(l<h){
            int md = (l+h) / 2;
            if(events[md][0] > cur)
                h = md;
            else
                l = md + 1;
        }
        return l;
    }

    int dfs(int i, int k, const vector<vector<int>>& events, vector<vector<int>>& memo) {
        if(i == events.size() || k == 0)return 0;
        if(memo[i][k] != -1)return memo[i][k];

        int skip = dfs(i+1,k,events,memo);

        int next_idx = nxt(events,events[i][1]);
        int taken = events[i][2] + dfs(next_idx,k-1,events,memo);

        return memo[i][k] = max(taken,skip);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        int n = events.size();
        vector<vector<int>> memo(n,vector<int>(k+1,-1));

        return dfs(0,k,events,memo);
    }
};
