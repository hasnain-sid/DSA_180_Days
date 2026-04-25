1class Solution:
2    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:    
3        ans = defaultdict(list)
4
5        for s in strs:
6            key = "".join(sorted(s))
7            ans[key].append(s)
8        
9        return list(ans.values())