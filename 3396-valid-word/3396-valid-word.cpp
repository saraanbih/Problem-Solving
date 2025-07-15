class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c); 
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    bool isValid(string word) {
        if(word.size() < 3)return false;
        bool v = false,c = false;
        for(auto &ch : word){
            if(!isalpha(ch) && !isdigit(ch))return false;
            if(isVowel(ch))v=true;
            else if(isalpha(ch)) c=true;
        }
        return (v&&c);
    }
};