class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if(x < y){
            int tmp = x;
            x = y;
            y = tmp;
            reverse(s.begin(),s.end());
        }
        int a = 0,b=0,total = 0;
        for(int i=0;i<s.size();i++){
            char cur = s[i];
            if(cur == 'a')a++;
            else if(cur == 'b'){
                if(a > 0){--a; total+=x;}
                else b++;
            }
            else{
                total += min(b,a) * y;
                a = b = 0;
            }
        }
        total += min(a,b) * y;
        return total;
    }
};