class Solution {
public:
    int countPalindromicSubsequence(string s) {
       unordered_set<char> letters;
       for(auto&ch:s) letters.insert(ch);
       int res = 0;
       for(auto &letter : letters){
           int first = -1 , end = 0;
           for(int i=0;i<s.length();i++){
              if(s[i] == letter){
                if(first == -1) first = i;
                end = i;
              }
           }
           unordered_set<char> between;
           for(int i=first+1;i<end;i++){
             between.insert(s[i]);
           }
           res+=between.size();
       }
       return res;
    }
};