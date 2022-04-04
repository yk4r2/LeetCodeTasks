class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        length = 0
        front, end, curr = None, None, head
        while curr is not None:
            length += 1
            if end is not None:
                end = end.next
            if length == k:
                front = curr
                end = head
            curr = curr.next
        temp = front.val
        front.val = end.val
        end.val = temp
        return head
