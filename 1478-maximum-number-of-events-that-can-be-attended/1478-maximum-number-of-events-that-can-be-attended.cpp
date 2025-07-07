class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // Sort events by their start day
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int n = events.size();
        int res = 0, day = 0, i = 0;
        
        // Loop until all events are processed and the heap is empty
        while (i < n || !minHeap.empty()) {
            // If no events are available, jump to next event's start day
            if (minHeap.empty())
                day = events[i][0];
            // Add all events starting today to the heap
            while (i < n && events[i][0] == day)
                minHeap.push(events[i++][1]);
            // Attend the event that ends earliest
            minHeap.pop();
            res++;
            day++;
            // Remove events that have already ended
            while (!minHeap.empty() && minHeap.top() < day)
                minHeap.pop();
        }
        return res;
    }
};
