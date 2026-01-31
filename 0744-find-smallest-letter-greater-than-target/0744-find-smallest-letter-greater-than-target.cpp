class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int mn = INT_MAX;
        char ans = letters[0];
        for(auto& letter : letters){
            int dist = letter - 'a';
            if((dist < mn) && (target - 'a' < dist)){
                mn = dist;
                ans = letter;
            }
        }
        return ans;
    }
};