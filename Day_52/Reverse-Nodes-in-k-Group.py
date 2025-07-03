# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:

        # Count nodes
        count = 0
        curr = head
        while curr and count < k:
            curr = curr.next
            count += 1
        
        if count == k:
            # Reverse first k nodes
            curr = self.reverseKGroup(curr, k)  # Recursively reverse rest
            
            # Reverse current group
            prev = curr
            current = head
            for _ in range(k):
                next_temp = current.next
                current.next = prev
                prev = current
                current = next_temp
            
            head = prev
        
        return head