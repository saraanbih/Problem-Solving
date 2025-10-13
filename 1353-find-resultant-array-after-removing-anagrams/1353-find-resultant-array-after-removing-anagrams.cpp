class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        string prev = "";
        vector<string> ans;
        for(auto &word : words){
            string sorted = word;
            sort(sorted.begin(),sorted.end());
            if(prev != sorted){
                ans.push_back(word);
                prev = sorted;
            }    
        }
        
        return ans;
    }
};