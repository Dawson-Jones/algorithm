class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


e1 = ListNode()


class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        li = []

        while head.next is not None:
            li.append(head.val)
            head = head.next
        li.append(head.val)
        li.reverse()
        for i in li:
            return i
