class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        add = 0
        dummy = ListNode(-1)
        header = dummy
        
        while l1 and l2:
            current = (l1.val + l2.val + add) % 10
            add = (l1.val + l2.val + add) // 10
            header.next = ListNode(current)
            header = header.next
            l1 = l1.next
            l2 = l2.next

        while l1:
            if not add:
                header.next = l1
                break
            else:
                current = (l1.val + add) % 10
                add = (l1.val + add) // 10
                header.next = ListNode(current)
                header = header.next
                l1 = l1.next
        
        while l2:
            if not add:
                header.next = l2
                break
            else:
                current = (l2.val + add) % 10
                add = (l2.val + add) // 10
                header.next = ListNode(current)
                header = header.next
                l2 = l2.next

        if add:
            header.next = ListNode(add)
        return dummy.next
