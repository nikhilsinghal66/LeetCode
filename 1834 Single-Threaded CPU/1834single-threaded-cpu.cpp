class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        
        vector<tuple<int, int, int>> sortedTasks(n);
        for (int i = 0; i < n; ++i) {
            sortedTasks[i] = {tasks[i][0], tasks[i][1], i};
        }
        
        sort(sortedTasks.begin(), sortedTasks.end());

        using Task = pair<int, int>;
        priority_queue<Task, vector<Task>, greater<Task>> availableTasks;

        vector<int> result;
        long long currentTime = 0;
        int taskIndex = 0;

        while (result.size() < n) {
            
            while (taskIndex < n && get<0>(sortedTasks[taskIndex]) <= currentTime) {
                availableTasks.push({get<1>(sortedTasks[taskIndex]), get<2>(sortedTasks[taskIndex])});
                taskIndex++;
            }

            if (availableTasks.empty()) {
                if (taskIndex < n) {
                    currentTime = get<0>(sortedTasks[taskIndex]);
                }
                continue;
            }

            Task nextTask = availableTasks.top();
            availableTasks.pop();

            currentTime += nextTask.first;
            
            result.push_back(nextTask.second);
        }

        return result;
    }
};