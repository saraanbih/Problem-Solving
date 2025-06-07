class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> pq;
        int n = s.length();
        unordered_map<int,bool> mp;
        for(int i = 0;i<s.length();i++){
            if(s[i] != '*')pq.push({s[i],-i});
            else{
                if(!pq.empty()){
                    int idx = pq.top().second; pq.pop();
                    mp[-idx] = true;
                }
            }
        }
        string res = "";
        for(int i = 0;i<s.length();i++){
            if(s[i] != '*' && !mp.count(i))res+=s[i];
        }
           
        return res;
    }
};