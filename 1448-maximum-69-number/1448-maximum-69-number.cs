public class Solution {
    public int Maximum69Number (int num) {
        string str = num.ToString();
        int ans = 0;
        bool tst = false;
        foreach(var ch in str){
            if(!tst && (ch == '6')){
                ans = (ans*10) + 9;
                tst = true;
            }
            else
                ans = (ans*10) + (ch-'0');
        }
        return ans;
    }
}