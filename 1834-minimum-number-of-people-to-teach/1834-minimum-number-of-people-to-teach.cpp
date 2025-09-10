class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> need_to_teach;
        for(auto &f : friendships){
            int u1 = f[0] - 1;
            int u2 = f[1] - 1;
            bool can_communicate = false;
            for(auto l1 : languages[u1]){
                for(auto l2 : languages[u2]){
                    if(l1 == l2){
                        can_communicate = true;
                        break;
                    }
                }
                if(can_communicate)break;
            }
            if(!can_communicate){
                need_to_teach.insert(u1);
                need_to_teach.insert(u2);
            }
        }

        int mn = languages.size() + 1;
        for(int i = 1;i<=n;i++){
            int cnt = 0;
            for(int u : need_to_teach){
                bool know = false;
                for(int l : languages[u]){
                    if(l == i){
                        know = true;
                        break;
                    }
                }
                if(!know) cnt++;
            }
            mn = min(mn,cnt);
        }
        return mn;
    }
};