# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def merge2Lists(self, list1, list2):
        head = point = ListNode(0)
        while list1 and list2:
            if list1.val <= list2.val:
                point.next = list1
                list1 = list1.next
            else:
                point.next = list2
                list2 = list1
                list1 = point.next.next
            point = point.next
        point.next = list2 if not list1 else list1
        return head.next
            
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        amount = len(lists)
        divisor = 1
        while divisor < amount:
            for i in range(0, amount - divisor, divisor * 2):
                lists[i] = self.merge2Lists(lists[i], lists[i + divisor])
            divisor *= 2
        return lists[0] if amount > 0 else None
