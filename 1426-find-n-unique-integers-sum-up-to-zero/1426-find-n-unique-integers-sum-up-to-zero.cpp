class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        int md = n / 2;
        for(int i=-1*md;i<=md;i++){
            if(n%2==0 && i == 0)continue;
            ans.push_back(i);
        }

        return ans;
    }
};