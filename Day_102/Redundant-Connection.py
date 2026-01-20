1class Solution:
2    def findRedundantConnection(self, edges: list[list[int]]) -> list[int]:
3        n = len(edges)
4        parent = list(range(n + 1))
5        
6        def find(node):
7            if parent[node] != node:
8                parent[node] = find(parent[node])  # Path compression
9            return parent[node]
10        
11        def union(node1, node2):
12            root1, root2 = find(node1), find(node2)
13            if root1 == root2:
14                return False  # Already connected = cycle!
15            parent[root1] = root2
16            return True
17        
18        for a, b in edges:
19            if not union(a, b):
20                return [a, b]
21        
22        return []
23
24# Example: edges = [[1,2], [2,3], [3,4], [1,4], [1,5]]
25
26
27# Initial: parent = [0, 1, 2, 3, 4, 5]
28#          (index 0 unused, nodes are 1-5)
29
30# Edge [1,2]:
31#   find_leader(1) = 1
32#   find_leader(2) = 2
33#   Different leaders → union them
34#   parent[1] = 2
35#   parent = [0, 2, 2, 3, 4, 5]
36
37# Edge [2,3]:
38#   find_leader(2) = 2
39#   find_leader(3) = 3
40#   Different → union
41#   parent[2] = 3
42#   parent = [0, 2, 3, 3, 4, 5]
43
44# Edge [3,4]:
45#   find_leader(3) = 3
46#   find_leader(4) = 4
47#   Different → union
48#   parent[3] = 4
49#   parent = [0, 2, 3, 4, 4, 5]
50
51# Edge [1,4]:
52#   find_leader(1) = ?
53#     parent[1] = 2
54#     parent[2] = 3
55#     parent[3] = 4
56#     parent[4] = 4 ✓
57#     Leader = 4
58#   find_leader(4) = 4
59  
60#   SAME LEADER! Already connected!
61#   Return [1, 4] ✅