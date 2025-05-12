class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int> st;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i == j)continue;
                for(int k = 0;k<n;k++){
                    if(k == i || k == j)continue;
                    int num = (digits[i]*10 + digits[j])*10 + digits[k];
                    if((num/100 > 0) && (num%2 == 0))st.insert(num);
                }
            }
        }
        vector<int> res;
        for(auto &ele:st)res.push_back(ele);
        return res;
    }
};