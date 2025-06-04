
class Solution {
public:
    string answerString(string word, int numFriends) {
         if (numFriends == 1) {
            return word;
        }
        int n = word.size();
        int mx_size = n - numFriends + 1;
        string res;
        for(int i = 0;i<n;i++){
            res = max(res,word.substr(i,min(n-i,mx_size)));
        }
        return res;
    }
};