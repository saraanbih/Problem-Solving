class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& h, vector<int>& v) {
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());

        int hmax = 1,vmax = 1;
        int hcur = 1,vcur = 1;

        for(int i=1;i<h.size();i++){
            if(h[i] == h[i-1] + 1)hcur++;
            else hcur=1;

            hmax = max(hmax,hcur);
        }

        for(int i=1;i<v.size();i++){
            if(v[i] == v[i-1] + 1)vcur++;
            else vcur=1;

            vmax = max(vmax,vcur);
        }

        int ans = min(hmax,vmax) + 1;
        return ans*ans;
    }
};