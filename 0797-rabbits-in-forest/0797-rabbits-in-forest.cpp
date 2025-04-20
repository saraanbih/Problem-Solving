class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        for(auto&n : answers)mp[n]++;
        int cnt = 0;
        for(auto&pair : mp){
           int sz = pair.first + 1;
           int g = (pair.second + sz - 1) / sz;
           cnt += g * sz;
        }
        return cnt;
    }
};