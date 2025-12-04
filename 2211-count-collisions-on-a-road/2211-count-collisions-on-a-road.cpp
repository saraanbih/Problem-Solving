class Solution {
public:
    int countCollisions(string directions) {
        int ans = 0;
        int var = -1;
        for(auto &d : directions){
            if(d == 'L'){
                if(var >= 0){
                    ans += var + 1;
                    var = 0;
                }
            }else if(d == 'S'){
                if(var > 0)ans += var;
                var = 0;
            }else{
                if(var >= 0)var++;
                else var = 1;
            }
        }
        return ans;
    }
};