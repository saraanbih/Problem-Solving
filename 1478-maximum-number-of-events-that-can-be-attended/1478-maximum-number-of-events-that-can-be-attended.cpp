class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
       sort(events.begin(),events.end());
       priority_queue<int,vector<int>,greater<int>>pq;
       int res = 0,day = 0,i=0;
       int n = events.size();
       while(i < n || !pq.empty()){
          if(pq.empty())
            day = events[i][0];
          while(i < n && events[i][0] == day)
            pq.push(events[i++][1]);
          pq.pop();
          res++;
          day++;
          while(!pq.empty() && pq.top() < day)
            pq.pop();
       }
       return res;
    }
};