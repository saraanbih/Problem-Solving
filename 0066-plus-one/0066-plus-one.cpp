class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        int c = 1;
        int n = d.size();
        for(int i=n-1;i>=0;i--){
            int s = c + d[i];
            d[i] = s%10;
            c = s/10;
        }
        if(c)
            d.insert(d.begin(),c);
        return d;
    }
};