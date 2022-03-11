class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        
        pointer = head
        length = 1
        while pointer.next:
            pointer = pointer.next
            length += 1
        pointer.next = head
        
        pointer = head
        for i in range(length - (k % length) - 1):
            pointer = pointer.next
        head = pointer.next
        pointer.next = None
        return head
