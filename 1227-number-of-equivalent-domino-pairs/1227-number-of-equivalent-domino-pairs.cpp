class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int,int> freq;
        for(auto&p : dominoes){
            int k = min(p[0],p[1])*10 + max(p[0],p[1]);
            freq[k]++;
        }
        int cnt = 0;
        for(auto&p : freq)if(p.second > 1){
            cnt+= ((p.second*(p.second-1))/2);
        }
        return cnt;
    }
};