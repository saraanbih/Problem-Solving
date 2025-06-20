class Solution {
public:
    int maxDistance(string str, int k) {
        int n = 0,s = 0,e = 0,w = 0;
        int ans = 0;
        for(int i = 0; i < str.size(); i++){
            char ch = str[i];
            if(ch == 'N')n++;
            else if(ch == 'W')w++;
            else if(ch == 'E')e++;
            else s++;
            int x = abs(n - s);
            int y = abs(e - w);
            int d = x + y;
            int dis = d + min(2*k,i+1-d);
            ans = max(ans,dis);
        }
        return ans;
    }
};