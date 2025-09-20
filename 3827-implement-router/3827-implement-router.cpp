class Router {
public:
    int limit = 0;
    set<vector<int>> packets;
    unordered_map<int, int> rmv;
    unordered_map<int, vector<int>> dt;

    queue<vector<int>> q;
    Router(int memoryLimit) { limit = memoryLimit; }

    bool addPacket(int source, int destination, int timestamp) {
        if (packets.find({source, destination, timestamp}) != packets.end())
            return false;
        
        if (q.size() > 0) {
            if (limit == q.size()) {
                vector<int> p = q.front();
                packets.erase(p);
                rmv[p[1]]++;
                q.pop();
            }
        }

        q.push({source, destination, timestamp});
        dt[destination].push_back(timestamp);
        packets.insert({source, destination, timestamp});
        return true;
    }

    vector<int> forwardPacket() {
        if (q.size() > 0) {
            vector<int> p = q.front();
            packets.erase(p);
            rmv[p[1]]++;
            q.pop();
            return p;
        }

        return {};
    }

    int getCount(int destination, int startTime, int endTime) {

        if (dt.find(destination) == dt.end()) {
            return 0;
        }

        int x = rmv[destination];

        auto it = lower_bound(dt[destination].begin() + x,
                              dt[destination].end(), startTime);

        auto it2 = upper_bound(dt[destination].begin() + x,
                               dt[destination].end(), endTime);

        int count = int(it2 - it);
        return count;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */