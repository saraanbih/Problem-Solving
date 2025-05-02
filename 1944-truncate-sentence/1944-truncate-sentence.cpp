class Solution {
public:
    #include <string>

std::string truncateSentence(const std::string& s, int k) {
    int count = 0;
    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] == ' ')
        {
            count++;
            if (count == k)
            {
                return s.substr(0, i);
            }
        }
    }
    return s;
}

};