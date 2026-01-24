class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if len(edges) != n - 1:
            return False
            
        parent = list(range(n))
        
        def find(node):
            if parent[node] != node:
                parent[node] = find(parent[node])  # Path compression
            return parent[node]
        
        def union(node1, node2):
            root1, root2 = find(node1), find(node2)
            if root1 == root2:
                return False  # Already connected = cycle!
            parent[root1] = root2
            return True
        
        for a, b in edges:
            if not union(a, b):
                return False
        
        return True
