class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
       for(int i = 1;i<=6 ;i++){
          int st = 0,sb = 0;
          bool can_swap = true;
          for(int j=0;j<tops.size();j++){
              if(tops[j] != i && bottoms[j] != i){
                 can_swap = false;
                 break;
              }
              if(tops[j] != i)st++;
              if(bottoms[j] != i)sb++;
          }
          if(can_swap) return min(st,sb);
       }
       return -1;
    }
};