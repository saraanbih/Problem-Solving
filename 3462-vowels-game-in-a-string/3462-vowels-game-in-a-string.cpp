class Solution {
public:
    bool doesAliceWin(string s) {
        unordered_set<char> vowels = {'a','e','i','u','o'};
        for(auto &ch : s){
            if(vowels.count(ch))return true;
        }
        
        return false;
    }
};