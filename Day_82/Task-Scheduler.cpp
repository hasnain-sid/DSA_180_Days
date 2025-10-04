class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(int i=0 ;i<tasks.size(); i++){
            freq[tasks[i]-'A']++;
        }
        sort(freq.begin(),freq.end());
        int idle_slots = (freq[25]-1)*n;
        for(int i=24;i>=0;i--){
            idle_slots -= min(freq[i],freq[25]-1);
        }
        if(idle_slots<0) return tasks.size();
        return idle_slots+tasks.size();       
        
    }
};