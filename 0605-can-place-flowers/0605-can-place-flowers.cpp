class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
       int cnt = 0;
       int sz = flowerbed.size();
       for(int i=0;i<flowerbed.size();i++){
           if(flowerbed[i] == 0){
                bool l = ((i==0) || (flowerbed[i-1] == 0)), r = ((i == sz-1) || (flowerbed[i+1] == 0));
                if(l && r){
                    flowerbed[i] = 1;
                    cnt++;
                    if(cnt >= n) return true; 
                }
           }
       }
       return cnt >= n;
    }
};