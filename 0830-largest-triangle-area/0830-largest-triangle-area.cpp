class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
       double ans = 0.0;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                for(int k=j+1;k<points.size();k++){
                    auto p1 = points[i],
                    p2 = points[j],
                    p3 = points[k];
                    int x1 = p1[0],y1 = p1[1];
                    int x2 = p2[0],y2 = p2[1];
                    int x3 = p3[0],y3=p3[1];
                    double area = 0.5 * abs(x1 * (y2-y3) + x2 * (y3-y1) + x3 * (y1-y2));
                    ans = max(ans,area);
                }
            }
        }
        return ans;
    }
};