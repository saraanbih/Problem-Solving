class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l=0,r=0,b=0;
        for(auto & move : moves){
            if(move == 'L')
                l++;
            else if(move == 'R')
                r++;
            else
                b++;
        }
        return abs(r - l) + b;
    }
};