class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        if(haystack.find(needle) == std::string::npos)
          return -1;
        else if(haystack.find(needle) != 0)
          return haystack.find(needle);
        else 
          return 0;
    }
};