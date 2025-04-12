class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> v;
        string word;
        while( ss >> word ){
            v.push_back(word);
        }
        reverse(v.begin(),v.end());
        string res;
        for(auto &str:v)
            res+=str+' ';
        if(!res.empty()) res.pop_back();
        return res;
    }
};
