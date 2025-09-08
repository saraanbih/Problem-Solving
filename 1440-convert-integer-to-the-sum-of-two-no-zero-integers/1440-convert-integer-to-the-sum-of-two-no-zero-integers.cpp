class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
         for(int i = 1;i<n;i++){
            int rem = n-i;
            string s1 = to_string(i),s2 = to_string(rem);
            if((s1.find('0') != std::string::npos) || 
            (s2.find('0') != std::string::npos)) continue;
            return {i,rem};
        }
        return {0,0};
    }
};