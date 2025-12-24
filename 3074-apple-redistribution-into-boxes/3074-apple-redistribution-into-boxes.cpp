class Solution {
public:
    int minimumBoxes(vector<int>& a, vector<int>& c) {
        sort(c.begin(),c.end());
        int total_apples = std::accumulate(a.begin(),a.end(),0);
        int min_c = 0, cnt = 0;
        for(int i=c.size()-1;i>=0;i--){
            min_c += c[i];
            if(min_c >= total_apples){
                cnt++;
                return cnt;
            }
            cnt++;
        }
        return cnt;
    }
};