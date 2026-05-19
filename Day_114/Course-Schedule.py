1from collections import defaultdict
2class Solution:
3    def detect_cycle(self, key, data_dict, checking, visited):
4        if key not in data_dict:
5            return False
6        for value in data_dict[key]:  
7            if value in checking:
8                return True
9            if value in visited:
10                continue
11            checking.append(value)
12            result = self.detect_cycle(value, data_dict, checking, visited)
13            if result:
14                return True
15            checking.remove(value)   
16            visited.add(value)       
17        return False
18
19    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
20        data_dict = defaultdict(list)
21        for [a,b] in prerequisites:
22            data_dict[b].append(a)
23        data_dict = dict(data_dict)  
24        visited = set()
25        for key in data_dict:        
26            if key in visited:
27                continue
28            checking = [key]
29            if self.detect_cycle(key, data_dict, checking, visited):
30                return False
31            visited.add(key)         
32
33        return True