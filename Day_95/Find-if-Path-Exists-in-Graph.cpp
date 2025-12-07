1class Solution {
2public:
3    bool check(unordered_map<int,vector<int>> &graph, vector<bool> &visited, int start, int end){
4        if(start == end) return true;
5        if(visited[start]) return false;
6        visited[start] = true;
7        for(auto it: graph[start]){
8            if(check(graph, visited, it, end)) return true;
9        }
10        return false;
11    }
12    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
13        unordered_map<int,vector<int>> graph; 
14        for(auto e : edges) {
15            graph[e[0]].push_back(e[1]);
16            graph[e[1]].push_back(e[0]);
17        }
18        vector<bool> visited(n,0);        
19        // return check(graph, visited, start, end);
20        queue<int> qt;
21        qt.push(start);
22        while(qt.size()){
23            int source = qt.front();
24            qt.pop();
25            if(source == end) return true;
26            for(auto it: graph[source]){
27                if(!visited[it])
28                    qt.push(it);
29                visited[it] = true;
30                
31            }
32            
33        }
34        return false;
35    }
36};