class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        vector<long long>lengths;
        long long len = 1;
        for(auto &op : operations){
            if(len >= k)break;
            len*=2;
            lengths.push_back(len);
        }
        int shift = 0;
       for (int i = (int)lengths.size() - 1; i >= 0; --i){
            len = lengths[i]/2;
            if(k > len){
                k-=len;
                if(operations[i] == 1)shift++;
            }
        }
        return ('a' + (shift%26));
    }
};