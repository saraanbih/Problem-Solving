class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        for(int i=1;i<=6;i++){
            int rt = 0,rb=0;
            bool can = true;
            for(int j=0;j<tops.size();j++){
                if(tops[j] != i && bottoms[j] != i){
                    can = false;
                    break;
                }
                if(tops[j] != i)rt++;
                if(bottoms[j] != i)rb++;
            }
            if(can)return min(rt,rb);
        }
        return -1;
    }
};