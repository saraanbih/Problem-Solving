class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }

        string result = "";
        
        if ((numerator < 0) ^ (denominator < 0)) {
            result += "-";
        }
        
        long long num = abs((long long)numerator);
        long long den = abs((long long)denominator);
        
        // Append integer part
        result += to_string(num / den);
        long long remainder = num % den;
        
        if (remainder == 0) {
            return result;
        }
        
        result += ".";
        unordered_map<long long, int> remainderMap;
        
        while (remainder != 0) {
            if (remainderMap.find(remainder) != remainderMap.end()) {
                int index = remainderMap[remainder];
                string non_repeating = result.substr(0, index);
                string repeating = result.substr(index);
                return non_repeating + "(" + repeating + ")";
            }
            
            remainderMap[remainder] = result.length();
            
            remainder *= 10;
            result += to_string(remainder / den);
            remainder %= den;
        }
        
        return result;
    }
};