# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        count = 0
        current = root
        
        while current:
            if not current.left:
                # Process current node
                count += 1
                if count == k:
                    return current.val
                current = current.right
            else:
                # Find inorder predecessor
                predecessor = current.left
                while predecessor.right:
                    predecessor = predecessor.right
                
                if not predecessor.right:
                    # Create thread
                    tmp = current
                    predecessor.right = current
                    current = current.left
                    tmp.left = None
                # else:
                #     # Remove thread and process
                #     predecessor.right = None
                #     count += 1
                #     if count == k:
                #         return current.val
                #     current = current.right
        
        return -1