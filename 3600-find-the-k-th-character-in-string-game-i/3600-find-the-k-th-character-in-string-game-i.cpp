class Solution {
public:
    char kthCharacter(int k) {
        string str = "a";
        while(str.size() < k){
            string nstr = "";
            for(auto &ch : str){
               char after = ((ch - 'a' + 1) % 26) + 'a'; 
               nstr += after;
            }
            str += nstr;
        }
        return str[k-1];
    }
};