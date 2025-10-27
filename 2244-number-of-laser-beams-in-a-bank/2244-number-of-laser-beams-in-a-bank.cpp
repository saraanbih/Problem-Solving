class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> ones;
        int ans = 0,prev = 0;
        for(auto & b : bank){
            int cnt = count(b.begin(),b.end(),'1');
            if(cnt == 0)continue;
            ans+=(prev*cnt);
            prev = cnt;
        }
        
        return ans;
    }
};