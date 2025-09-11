class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;
        unordered_set<char> v = {'a','e','o','i','u'
        ,'A','E','I','O','U'};        
        for(int i=0;i<s.length();i++){
            if(v.find(s[i]) != v.end()){
                vowels.push_back(s[i]);
            }
        }
        sort(vowels.begin(),vowels.end());
        int idx = 0;
        for(int i=0;i<s.length();i++){
            if(v.count(s[i])){
                s[i] = vowels[idx++];
            }
        }
        return s;
    }
};