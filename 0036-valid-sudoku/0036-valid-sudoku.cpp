class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> r(9),c(9),b(9);
        int n = board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == '.') continue;
                int idx = (i/3)*3+(j/3);
                int num = board[i][j] - '0';
                int mask = 1<<num;
                if(r[i]&mask || c[j]&mask || b[idx]&mask) return false;
                r[i]|=mask; c[j]|=mask; b[idx]|=mask;
            }
        }
        return true;
    }
};