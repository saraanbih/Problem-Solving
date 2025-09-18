class TaskManager {
public:
    unordered_map<int, pair<int, int>> tsks;
    priority_queue<pair<int, int>> highest_priority;

    TaskManager(vector<vector<int>>& tasks) {
        for (auto& tsk : tasks) {
            tsks[tsk[1]] = {tsk[0], tsk[2]};
            highest_priority.push({tsk[2], tsk[1]});
        }
    }

    void add(int userId, int taskId, int priority) {
        tsks[taskId] = {userId, priority};
        highest_priority.push({priority, taskId});
    }

    void edit(int taskId, int newPriority) {
        // Update the priority in the hash map
        tsks[taskId].second = newPriority;
        // Add the task with the new priority to the priority queue
        highest_priority.push({newPriority, taskId});
    }

    void rmv(int taskId) {
        // Remove the task from the hash map, effectively "deleting" it
        tsks.erase(taskId);
    }

    int execTop() {
        // Use a loop to handle "lazy deletion" from the priority queue
        while (!highest_priority.empty()) {
            auto top_task = highest_priority.top();
            highest_priority.pop();
            int current_priority = top_task.first;
            int current_taskId = top_task.second;

            // Check if the task still exists in the hash map
            if (tsks.count(current_taskId)) {
                // Check if the priority in the queue is still valid
                // This handles cases where a task was "edited"
                if (tsks[current_taskId].second == current_priority) {
                    int user_id = tsks[current_taskId].first;
                    tsks.erase(current_taskId); // Permanently remove after execution
                    return user_id;
                }
            }
        }
        return -1; // No tasks to execute
    }
};