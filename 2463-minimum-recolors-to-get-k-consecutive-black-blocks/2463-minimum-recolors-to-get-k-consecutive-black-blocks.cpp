class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int res = INT_MAX;
        for(int i=0;i<blocks.length();i++){
            for(int j=i;j+k<=blocks.size();j++){
                int op = count(blocks.begin()+j,blocks.begin()+j+k,'W');
                res = min(res,op);
            }
        }
        return res;
    }
};