class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for(auto &g : grid){
            for(int i=g.size()-1;i>=0;i--){
                if(g[i]>=0)break;
                ans++;
            }
        }
        return ans;
    }
};