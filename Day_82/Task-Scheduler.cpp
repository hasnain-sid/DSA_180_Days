class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        map<char,int> mp;
        for(auto it:tasks){
            mp[it]++;
        }
        int ans = 0;
        for(auto it:mp){
            pq.push(it.second);
        }
        while(!pq.empty()){
            int limit = n+1,done = 0;
            vector<int> rem;
            while(limit and !pq.empty()){
                int maxm = pq.top();
                pq.pop();
                done++;
                if(maxm-1>0){
                    rem.push_back(maxm-1);
                }
                limit--;
            }
            for(auto it:rem) pq.push(it);     
            if(pq.empty())ans+=done;
            else ans+= n+1;   
             
        }
        return ans;
    }
};