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
        for(int i=0;i<s.length();i++){
            if(v.count(s[i]) && vowels.size() > 0){
                auto val = *vowels.begin();
                s[i] = val;
                vowels.erase(vowels.begin());
            }
        }
        return s;
    }
};