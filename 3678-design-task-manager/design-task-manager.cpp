class TaskManager {
public:
    priority_queue<pair<int,int>>pq;
    unordered_map<int,int>pri_mp;
    unordered_map<int,int>task_ow;

    TaskManager(vector<vector<int>>& tasks) {
        for(auto &task:tasks){
            add(task[0],task[1],task[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        pq.push({priority,taskId});
        pri_mp[taskId]=priority;
        task_ow[taskId]=userId;
    }
    
    void edit(int taskId, int newPriority) {
        pq.push({newPriority,taskId});
        pri_mp[taskId]=newPriority;
    }
    
    void rmv(int taskId) {
        pri_mp[taskId]=-1;
    }
    
    int execTop() {
        while(pq.size()>0){
            auto [prio,taskid]=pq.top();
            pq.pop();
            if(prio==pri_mp[taskid]){
                pri_mp[taskid]=-1;
                return task_ow[taskid];
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