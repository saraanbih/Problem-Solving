class Solution {
public:
    vector<string> v;
    void go(string s,int n){
        if(s.length() == n){
            v.push_back(s);
            return;
        } 
        for(auto &ch : {'a','b','c'}){
            if(s.empty() || s.back() != ch)
                go(s+ch,n);
        }
    }
    string getHappyString(int n, int k) {
        go("",n);
        sort(v.begin(),v.end());
        if(v.size() >= k) return v[k-1];
        return "";
    }
};