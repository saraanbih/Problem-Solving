class Solution {
public:
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<char> parent(26);
        for(int i=0;i<26;i++)
            parent[i] = 'a' + i;
        function<char(char)> find = [&](char x) -> char{
            if(parent[x-'a'] == x)return x;
            return parent[x-'a'] = find(parent[x-'a']);
        };

        auto merge = [&](char a,char b){
            char pa = find(a);
            char pb = find(b);
            if(pa == pb) return;
            if(pa < pb)
                parent[pb-'a'] = pa;
            else
                parent[pa-'a'] = pb;
        };

        for(int i=0;i<s1.size();i++)
            merge(s1[i],s2[i]);

        string res;
        for(auto &ch : baseStr)
            res += find(ch);
        return res;
    }
};