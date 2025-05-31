class Solution {
public:
    pair<int, int> getPosition(int s, int n) {
        int s0 = s - 1;
        int row = n - 1 - s0 / n;
        int col;
        if ((n - 1 - row) % 2 == 0) {
            col = s0 % n;
        } else {
            col = n - 1 - (s0 % n);
        }
        return {row, col};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<int> q;
        q.push(1);
        int steps = 0;
        vector<bool> vis(n * n + 1, false); 
        vis[1] = true;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                int cur = q.front(); q.pop();
                if(cur == n*n)return steps;
                for(int move=1;move<=6 && move+cur<=n*n;++move){
                    int nxt = cur + move;
                    auto [r,c] = getPosition(nxt,n);
                    if(board[r][c] != -1)
                        nxt = board[r][c];
                    if(!vis[nxt]){
                        vis[nxt] = true;
                        q.push(nxt);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};