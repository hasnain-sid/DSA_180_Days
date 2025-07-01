# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        Standard 3-step approach: Find middle -> Reverse second half -> Merge
        """
        if not head or not head.next:
            return
        
        # Step 1: Find the middle of the list
        slow = fast = head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        
        # Step 2: Reverse the second half
        second_half = slow.next
        slow.next = None  # Split the list
        
        prev = None
        curr = second_half
        while curr:
            next_temp = curr.next
            curr.next = prev
            prev = curr
            curr = next_temp
        second_half = prev  # Now points to the new head of reversed second half
        
        # Step 3: Merge the two halves alternately
        first_half = head
        while second_half:  # second_half will be shorter or equal
            # Save next nodes
            first_next = first_half.next
            second_next = second_half.next
            
            # Insert second_half node after first_half node
            first_half.next = second_half
            second_half.next = first_next
            
            # Move to next nodes
            first_half = first_next
            second_half = second_next

# Example dry run:
# Input: [1,2,3,4,5]
# 
# Step 1 - Find middle:
# slow ends at node 3, fast at node 5
# 
# Step 2 - Split and reverse:
# first_half: 1->2->3->None
# second_half: 5->4->None (reversed from 4->5)
# 
# Step 3 - Merge:
# Iteration 1: 1->5->2->3->None, second_half: 4->None
# Iteration 2: 1->5->2->4->3->None, second_half: None
# 
# Final result: 1->5->2->4->3