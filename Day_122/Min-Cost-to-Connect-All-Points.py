1class Solution:
2    def minCostConnectPoints(self, points: List[List[int]]) -> int:
3        n = len(points)
4        parent = list(range(len(points)))
5        rank = [0] * n
6        def find(x):
7            if parent[x] != x:
8                parent[x] = find(parent[x])
9            return parent[x]
10
11        def union(a: int, b: int) -> bool:
12            root_a = find(a)
13            root_b = find(b)
14
15            if root_a == root_b:
16                return False
17
18            if rank[root_a] < rank[root_b]:
19                parent[root_a] = root_b
20            elif rank[root_a] > rank[root_b]:
21                parent[root_b] = root_a
22            else:
23                parent[root_a] = root_b
24                rank[root_b] += 1
25
26            return True
27
28        edges = [] 
29
30        for i in range(len(points)):
31            for j in range(i+1, len(points)):
32                
33                weight= abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1])
34                edges.append((weight, i, j))
35
36        edges.sort()
37        
38
39        minimum_cost = 0
40        path = 0
41        
42        for edge in edges:
43            if not union(edge[1], edge[2]):
44                continue
45            path += 1
46            if path > n - 1: #as there are only n-1 edge is requried to connect all n nodes
47                return minimum_cost
48            minimum_cost += edge[0]
49
50        return minimum_cost
51