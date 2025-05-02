class Solution {
public:
    int numJewelsInStones(string jewels, string stones) 
    {
        unordered_map<char,int> um;
        int cnt=0;
        for(int i=0;i<jewels.size();i++)
        {
            um[jewels[i]] = i;
        }
        for(int i=0;i<stones.size();i++)
        {
            if(um.count(stones[i])) cnt++;
        }
        return cnt;
    }
};