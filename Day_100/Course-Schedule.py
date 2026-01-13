1class Solution:
2    def canFinish(self, numCourses: int, prerequisites: list[list[int]]) -> bool:
3        # Build adjacency list
4        graph = [[] for _ in range(numCourses)]
5        for course, prereq in prerequisites:
6            graph[prereq].append(course)
7        
8        # 0 = unvisited, 1 = visiting, 2 = visited
9        state = [0] * numCourses
10        
11        def has_cycle(course):
12            if state[course] == 1:  # Currently visiting - cycle!
13                return True
14            if state[course] == 2:  # Already done
15                return False
16            
17            state[course] = 1  # Mark as visiting
18            
19            for next_course in graph[course]:
20                if has_cycle(next_course):
21                    return True
22            
23            state[course] = 2  # Mark as visited
24            return False
25        
26        # Check all courses (handles disconnected components)
27        for course in range(numCourses):
28            if has_cycle(course):
29                return False
30        
31        return True