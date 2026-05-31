1class Solution:
2    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
3        
4        n = len(edges)+1
5        parents = list(range(n))
6        size = [1]*n
7        print(parents)
8
9        def find(x):
10            
11            if parents[x] != x:
12                parents[x] = find(parents[x])
13            return parents[x]
14            # while parents[x] != x:
15            #     x = parents[x]
16            # return x
17
18        def union(a, b):
19            root_a = find(a)
20            root_b = find(b)
21
22            if root_a == root_b:
23                return False
24            # parents[root_b] = root_a
25            if size[root_a] < size[root_b]:
26                root_a, root_b = root_b, root_a
27
28            parents[root_b] = root_a
29            size[root_a] += size[root_b]
30            return True
31        
32        for a,b in edges:
33            if not union(a,b):
34                return [a,b]
35
36        return []