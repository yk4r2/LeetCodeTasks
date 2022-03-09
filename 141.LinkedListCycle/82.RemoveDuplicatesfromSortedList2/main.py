class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        if not head.next.next:
            return None if head.next.val == head.val else head
        dummy = ListNode(-1, head)
        last = dummy
        slow = head
        fast = head.next
        while fast:
            while fast and fast.val == slow.val:
                fast = fast.next
            if fast != slow.next:
                last.next = fast
            else:
                last = slow
            slow = fast
            fast = fast.next if fast else None
        return dummy.next
