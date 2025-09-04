class Solution {
public:
    int findClosest(int x, int y, int z) {
        int d1 = abs(z-x);
        int d2 = abs(z-y);
        if(d1 == d2)return 0;
        return (d1 > d2 ? 2 : 1);
    }
};