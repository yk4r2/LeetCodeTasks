# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        prehead = ListNode(-1)
        prehead.next = head
        
        prev = prehead
        
        while head and head.next:
            left = head
            right = head.next
            
            prev.next = right
            left.next = right.next
            right.next = left
        
            prev = left
            head = prev.next
        return prehead.next
