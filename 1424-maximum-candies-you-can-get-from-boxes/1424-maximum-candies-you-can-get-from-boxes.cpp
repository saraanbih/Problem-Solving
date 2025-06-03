class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,  vector<vector<int>>& keys,vector<vector<int>>& containedBoxes,vector<int>& initialBoxes) {
        int n = status.size();
        queue<int> q;
        unordered_set<int> boxes;
        vector<bool> vis(n,false),has_key(n,false);
        for(auto init: initialBoxes){
            boxes.insert(init);
        }
        int ans = 0;
        bool progress = true;
        while(progress){
            progress = false;
            vector<int> rem;
            for(auto box : boxes){
                if((status[box] == 1 || has_key[box]) && !vis[box]){
                    progress = true;
                    vis[box] = true;
                    ans += candies[box];
                    rem.push_back(box);
                    for(auto &key : keys[box]){
                        has_key[key] = true;
                    }
                    for(auto &con : containedBoxes[box]){
                        boxes.insert(con);
                    }
                }
                
            }
            for(auto &r : rem){
                boxes.erase(r);
            }
        }
        return ans;
    }
};