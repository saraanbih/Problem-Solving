class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> res(n,0);
        //LTR
        int balls  = 0,operations = 0;
        for(int i=0;i<n;i++){
            res[i] += operations;
            if(boxes[i] == '1') balls++;
            operations += balls;
        }
        //RTL
        balls=0;operations=0;
        for(int i=n-1;i>=0;i--){
            res[i] += operations;
            if(boxes[i] == '1') balls++;
            operations += balls;
        }
        return res;
    }
};