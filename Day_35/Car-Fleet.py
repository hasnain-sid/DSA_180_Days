class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        ans = 0
        st = []
        st.append(-1)
        for pp, ss in sorted(zip(position, speed), reverse=True): 
            tt = (target - pp)/ss # time to arrive at target 
            if st and st[-1] < tt: 
                ans += 1
                st.append(tt)
        return ans 