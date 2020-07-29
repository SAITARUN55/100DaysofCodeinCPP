class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> ch (26, 0);
        for(auto task: tasks)
            ch[task-'A']++;
        sort(ch.begin(), ch.end());
        int maxTotalSlots = ch[25] - 1;
        int idleSlots = maxTotalSlots * n;
        
        for(int i = 24; i >= 0; i--)
        {
            if(!ch[i])
                break;
            idleSlots -= min(ch[i], maxTotalSlots);
        }
        return tasks.size() + (idleSlots > 0 ? idleSlots : 0);
    }
};
