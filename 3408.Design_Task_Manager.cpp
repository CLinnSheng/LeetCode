#include <algorithm>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
/*
 * tasks[i] = [userId, taskId, priority]
 * add() -> add the task with specified taskId & priority to the user with userId. --> Hashmap to easily get the taskid
 * of a user edit() -> updates the priority of the existing taskId to newPriority, What data structure can we use to
 * easily access the taskId and edit it? rmv() -> Remove the task identified by taskId. same with edit execTop() -> Exec
 * the task with the highest priority across all user. Priority queue
 *
 *
 * */
class TaskManager
{
  private:
    std::priority_queue<std::pair<int, int>> tasksPQ;
    std::unordered_map<int, int> taskIdUser, taskPriority;

  public:
    TaskManager(std::vector<std::vector<int>> &tasks)
    {
        for (const auto &task : tasks)
        {
            auto userId{task[0]}, taskId{task[1]}, priority{task[2]};

            tasksPQ.emplace(priority, taskId);
            taskIdUser[taskId] = userId;
            taskPriority[taskId] = priority;
        }
    }

    void add(int userId, int taskId, int priority)
    {
        tasksPQ.emplace(priority, taskId);
        taskIdUser[taskId] = userId;
        taskPriority[taskId] = priority;
    }

    void edit(int taskId, int newPriority)
    {
        tasksPQ.emplace(newPriority, taskId);
        taskPriority[taskId] = newPriority;
    }

    void rmv(int taskId)
    {
        // Use for checking because we push the edited priority into the heap instead of edit it
        taskPriority[taskId] = -1;
    }

    int execTop()
    {
        while (!tasksPQ.empty())
        {
            auto top{tasksPQ.top()};
            tasksPQ.pop();

            if (top.first == taskPriority[top.second])
            {
                // Update it because we exec -> remove
                this->rmv(top.second);
                return taskIdUser[top.second];
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
