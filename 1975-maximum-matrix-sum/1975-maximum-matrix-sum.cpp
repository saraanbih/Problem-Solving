class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int r = matrix.size(),c=matrix[0].size(),
        neg = 0,small=INT_MAX;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                sum+=abs(matrix[i][j]);
                if(matrix[i][j] < 0) neg++;
                small = min(small,abs(matrix[i][j]));
            }
        }
        if(neg % 2 == 0) return sum;

        return sum - 2*small;
        
    }
};