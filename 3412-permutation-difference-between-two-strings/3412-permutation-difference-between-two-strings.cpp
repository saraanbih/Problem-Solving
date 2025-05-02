class Solution {
public:
    int findPermutationDifference(string s, string t)
    { 
        int Result = 0;
        int pos;
        for(int i=0;i<s.length();i++)
        {
            pos = t.find(s[i]);
            if(pos != std::string::npos)
                Result+=abs(i - pos);
        }
        
        return Result;
    }
};