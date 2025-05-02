class Solution:
    def isValid(self, s: str) -> bool:
        if len(s)%2==1:return False
        brac={'(':')','{':'}','[':']'}
        stack=[]
        for c in s:
            if c=='(' or c=='{' or c=='[':
                stack.append(c)
            elif not stack or brac[stack.pop()]!=c:
                return False
        return not stack