1class Solution:
2    def isAnagram(self, s: str, t: str) -> bool:
3        
4        if len(s) != len(t):
5            return False
6
7        string_set = set(s)
8
9        for char in string_set:
10            if s.count(char) != t.count(char):
11                return False
12        return True
13