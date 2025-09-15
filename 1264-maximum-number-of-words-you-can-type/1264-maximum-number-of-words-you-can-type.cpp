class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> not_work(brokenLetters.begin(),brokenLetters.end());
       
        stringstream ss(text);
        string str;
        int cnt = 0;
        while(ss >> str){
            bool can = true;
            for(auto &ch : str){
               if(not_work.count(ch)){
                    can = false;
                    break;
                }
            }
            if(can)cnt++;
        }
        return cnt;
    }
};