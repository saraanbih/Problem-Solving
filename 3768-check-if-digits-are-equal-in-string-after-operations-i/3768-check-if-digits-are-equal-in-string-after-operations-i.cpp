class Solution {
public:
    bool hasSameDigits(string s) {
        string str = "";
        while(s.size() != 2){
            for(int i = 0;i<s.length()-1;i++){
                int fnum = s[i] - '0',
                snum = s[i+1] - '0';
                int res = (fnum + snum)%10;
                str += to_string(res);
            }
            s = str;
            str = "";
            cout << s << endl;
        }
        
        if(s[0] == s[1]) return true;
        
        return false;
    }
};