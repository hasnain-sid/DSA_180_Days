1from collections import defaultdict
2from heapq import heappush, heappop
3class Solution:
4    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
5        graph = defaultdict(list)
6        
7        for u, v, w in times: 
8            graph[u].append((v, w))
9
10        dist = [float('inf')] * (n + 1)
11        dist[k] = 0
12
13        heap = [(0, k)]
14
15        while heap:
16            curr_time, node = heappop(heap)
17
18            if curr_time > dist[node]:
19                continue
20
21            for nei, weight in graph[node]:
22                new_time = curr_time + weight
23
24                if new_time < dist[nei]:
25                    dist[nei] = new_time
26                    heappush(heap, (new_time, nei))
27        ans = max(dist[1:])
28        return -1 if ans == float('inf') else ans