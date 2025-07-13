class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t){
        sort(p.begin(),p.end());
        sort(t.begin(),t.end());
        int n = p.size(),m=t.size();
        int cnt = 0;
        for(int i = 0,j = 0; i < n && j < m;i++,j++){
            if(p[i] <= t[j])cnt++;
            else{
                while(++j < m){
                    if(p[i] <= t[j]){
                        cnt++;
                        break;
                    }
                }
            }
        }
        return cnt;
    }
};