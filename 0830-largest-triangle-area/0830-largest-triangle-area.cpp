class Solution {
public:
    double largestTriangleArea(std::vector<std::vector<int>>& points) {
        double max_area = 0.0;
        const int N = points.size(); 

        for (int i = 0; i < N; ++i) {
            const auto& p1 = points[i];
            int x1 = p1[0], y1 = p1[1];
            
            for (int j = i + 1; j < N; ++j) {
                const auto& p2 = points[j];
                int x2 = p2[0], y2 = p2[1];
                
                for (int k = j + 1; k < N; ++k) {
                    const auto& p3 = points[k];
                    int x3 = p3[0], y3 = p3[1];
                    
                    long long determinant = (long long)x1 * (y2 - y3) + 
                                            (long long)x2 * (y3 - y1) + 
                                            (long long)x3 * (y1 - y2);
                    
                    double current_area = 0.5 * abs(determinant);
                    
                    max_area = max(max_area, current_area);
                }
            }
        }
        return max_area;
    }
};