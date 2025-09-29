#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int L = 2; L < n; ++L) {
            
            for (int i = 0; i < n - L; ++i) {
                
                int j = i + L;
                
                dp[i][j] = INT_MAX;
                
                for (int k = i + 1; k < j; ++k) {
                    
                    int triangle_score = values[i] * values[k] * values[j];
                    
                    int left_score = dp[i][k];
                    
                    int right_score = dp[k][j];
                    
                    int total_score = triangle_score + left_score + right_score;
                    
                    dp[i][j] = min(dp[i][j], total_score);
                }
            }
        }
        
        return dp[0][n - 1];
    }
};