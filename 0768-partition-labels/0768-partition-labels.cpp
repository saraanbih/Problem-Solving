class Solution {
public:
    vector<int> partitionLabels(string s) {
        int lst[26] = {0};
        for(int i=0;i<s.length();i++)lst[s[i] - 'a'] = i;
        vector<int> ans;int st = 0,mx_lst = 0;
        for(int i=0;i<s.length();i++){
            mx_lst = max(mx_lst,lst[s[i] - 'a']);
            if(mx_lst == i){
                ans.push_back(i - st + 1);
                st = i+1;
            }
        }
        return ans;
    }
};
