class Solution {
public:
    static bool isVowel(char c) {
        c = tolower((unsigned char)c);
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }

    static string toLowerStr(const string &s) {
        string r = s;
        for (char &c : r) c = tolower((unsigned char)c);
        return r;
    }

    static string devowel(const string &s) {
        string r = toLowerStr(s);
        for (char &c : r) if (isVowel(c)) c = '#';
        return r;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string,string> caseInsensitive;
        unordered_map<string,string> vowelMap;

        for (const auto &w : wordlist) {
            string lw = toLowerStr(w);
            if (!caseInsensitive.count(lw)) caseInsensitive[lw] = w;

            string dv = devowel(lw); 
            if (!vowelMap.count(dv)) vowelMap[dv] = w;
        }

        vector<string> ans;
        ans.reserve(queries.size());
        for (const auto &q : queries) {
            if (exact.count(q)) {                
                ans.push_back(q);
                continue;
            }
            string lq = toLowerStr(q);
            if (caseInsensitive.count(lq)) {    
                ans.push_back(caseInsensitive[lq]);
                continue;
            }
            string dq = devowel(lq);            // vowel-error match
            if (vowelMap.count(dq)) ans.push_back(vowelMap[dq]);
            else ans.push_back("");
        }
        return ans;
    }
};
