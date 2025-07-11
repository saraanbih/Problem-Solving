class Solution {
public:
    #define ll long long
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        priority_queue<int, vector<int>, greater<int>> free;
        for(int i=0;i<n;i++)free.push(i);
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>>
        busy;
        vector<int> mcnt(n,0);

        for(auto &m : meetings){
            ll st = m[0],ed = m[1];
            ll d = ed - st;
            while(!busy.empty() && busy.top().first <= st){
                int room = busy.top().second;
                busy.pop();
                free.push(room);
            }
            if(!free.empty()){
                int room = free.top();
                free.pop();
                busy.push({ed,room});
                mcnt[room]++;
            }
            else{
                auto [ava, room] = busy.top();
                busy.pop();
                ll ned = ava + d;
                busy.push({ned,room});
                mcnt[room]++;
            }
        }  
        int mx_m = 0, m_mx = 0;
        for(int i=0;i<n;i++){
            if(mcnt[i] > mx_m){
                mx_m = mcnt[i];
                m_mx = i;
            }
        }       
        return m_mx;
    }

  
};